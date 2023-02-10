#define _USE_MATH_DEFINES
#include "Drone.h"
#include "BeelineStrategy.h"
#include "DfsStrategy.h"
#include "AstarStrategy.h"
#include "DijkstraStrategy.h"
#include "SpinDecorator.h"
#include "JumpDecorator.h"
#include "DataCollector.h"

#include <cmath>
#include <limits>

Drone::Drone(JsonObject& obj) : details(obj) {
  JsonArray pos(obj["position"]);
  position = {pos[0], pos[1], pos[2]};

  JsonArray dir(obj["direction"]);
  direction = {dir[0], dir[1], dir[2]};

  speed = obj["speed"];
  std::string names = obj["name"];
  name = names;
  
  available = true;
  
  // DataCollector& dc = DataCollector::Get();
  DataCollector& dc = DataCollector::Get();
  dc.AddObject(this);
}

Drone::~Drone() {
  // Delete dynamically allocated variables
}

void Drone::GetNearestEntity(std::vector<IEntity*> scheduler) {
  float minDis = std::numeric_limits<float>::max();
  for (auto entity : scheduler) {
    if (entity->GetAvailability()) {
      float disToEntity = this->position.Distance(entity->GetPosition());
      if (disToEntity <= minDis) {
        minDis = disToEntity;
        nearestEntity = entity;
      }
    }
  }

  if(nearestEntity){
    nearestEntity->SetAvailability(false);  // set availability to the nearest entity
    available = false;
    pickedUp = false;

    destination = nearestEntity->GetPosition();

    toTargetPosStrategy = new BeelineStrategy(this->GetPosition(), destination);
    std::string targetStrategyName = nearestEntity->GetStrategyName();
    if(targetStrategyName.compare("astar") == 0){
        toTargetDestStrategy = new AstarStrategy(nearestEntity->GetPosition(), nearestEntity->GetDestination(), graph);
        toTargetDestStrategy = new SpinDecorator(toTargetDestStrategy);
    } else if (targetStrategyName.compare("dfs") == 0){
        toTargetDestStrategy = new DfsStrategy(nearestEntity->GetPosition(), nearestEntity->GetDestination(), graph);
        toTargetDestStrategy = new JumpDecorator(toTargetDestStrategy);
    } else if (targetStrategyName.compare("dijkstra") == 0){
        toTargetDestStrategy = new DijkstraStrategy(nearestEntity->GetPosition(), nearestEntity->GetDestination(), graph);
        toTargetDestStrategy = new SpinDecorator(toTargetDestStrategy);
        toTargetDestStrategy = new JumpDecorator(toTargetDestStrategy);
    } 
  }
}

void Drone::Update(double dt, std::vector<IEntity*> scheduler) {
  if (available) {
    GetNearestEntity(scheduler);
  }
  DataCollector& dc = DataCollector::Get();
  if(toTargetPosStrategy){
    
    currPosition = this->GetPosition();
    toTargetPosStrategy->Move(this, dt);
    movedPosition = this->GetPosition();

    dc.SetDistance(currPosition, movedPosition, name);
    if(toTargetPosStrategy->IsCompleted()){
      dc.AddRobot(name);
      delete toTargetPosStrategy;
      toTargetPosStrategy = NULL;
    }
  } else if (toTargetDestStrategy) {
    
    currPosition = this->GetPosition();
    toTargetDestStrategy->Move(this, dt);
    movedPosition = this->GetPosition();
    dc.SetDistance(currPosition, movedPosition, name);
    std::string robotName = nearestEntity->GetName();
    dc.SetDistance(currPosition, movedPosition, robotName);
    // Moving the robot
    nearestEntity->SetPosition(this->GetPosition());
    nearestEntity->SetDirection(this->GetDirection());
    if(toTargetDestStrategy->IsCompleted()){
        delete toTargetDestStrategy;
        toTargetDestStrategy = NULL;
        available = true;
        nearestEntity = NULL;
    }
  }  
}

void Drone::Rotate(double angle) {
  Vector3 dirTmp = direction;
  direction.x = dirTmp.x * std::cos(angle) - dirTmp.z * std::sin(angle);
  direction.z = dirTmp.x * std::sin(angle) + dirTmp.z * std::cos(angle);
}

void Drone::Jump(double height) {
  if(goUp){
    position.y += height;
    jumpHeight += height;
    if(jumpHeight > 5){
      goUp = false;
    }
  } else {
    position.y -= height;
    jumpHeight -= height;
    if(jumpHeight < 0){
      goUp = true;
    }
  }
}
