#ifndef ROBOT_H
#define ROBOT_H

#include <vector>

#include "IEntity.h"
#include "math/vector3.h"
#include "util/json.h"

/**
 * @brief Represents a robot in the physical system
 */ 
class Robot : public IEntity {
 public:
 /**
  * @brief Robot created from a json object
  * 
  * @param[in] obj The json object containing the robot's information
  */
  Robot(JsonObject& obj);

 /**
  * @brief Destructor
  */
  ~Robot() override = default;

 /**
  * @brief Get the robot's position
  * 
  * @return The robot's positioning represented as a 3D vector
  */
  Vector3 GetPosition() const { return position; }

 /**
  * @brief Get the robot's direction
  * 
  * @return The robot's orientation represented as a 3D vector
  */
  Vector3 GetDirection() const { return direction; }

 /**
  * @brief Get the robot's destination
  * 
  * @return The robot's goal coordinates represented as a 3D vector
  */
  Vector3 GetDestination() const { return destination; }

 /**
  * @brief Get the robot's availability
  * 
  * @return A bool representing if a robot is already in service
  */
  bool GetAvailability() const { return available; }

 /**
  * @brief Get the robot's details
  * 
  * @return A json object containing the robot's information
  */
  JsonObject GetDetails() const override;

 /**
  * @brief Get the robot's speed
  * 
  * @return The robot's speed represented as a float 
  */
  float GetSpeed() const { return speed; }

 /**
  * @brief Get the strategy being used by the robot
  * 
  * @return The movement strategy being used  
  */
  std::string GetStrategyName() {return strategyName;}

 /**
  * @brief Get the robot's name
  * 
  * @return The robot's name 
  */
  std::string GetName() {return name;}

 /**
  * @brief Set the robot's availability
  * 
  * @param[in] choice A bool representing the robot's availability   
  */
  void SetAvailability(bool choice);

 /**
  * @brief Set the robot's position
  * 
  * @param[in] pos The 3D vector that will be used as the robot's position  
  */
  void SetPosition(Vector3 pos_) { position = pos_; }

 /**
  * @brief Set the robot's direction
  * 
  * @param[in] dir The 3D vector that will be used as the robot's direction  
  */ 
  void SetDirection(Vector3 dir_) { direction = dir_; }

 /**
  * @brief Set the robot's destination
  * 
  * @param[in] des The 3D vector that will be used as the robot's destination  
  */
  void SetDestination(Vector3 des_) { destination = des_; }

 /**
  * @brief Set the strategy to be used by the robot
  * 
  * @param[in] strategyName The movement strategy being assigned to the robot  
  */
  void SetStrategyName(std::string strategyName_)
  { strategyName = strategyName_;}

 /**
  * @brief Rotate the robot by a desired angle
  * 
  * @param[in] angle The angle to which the robot is rotated   
  */
  void Rotate(double angle);

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  Vector3 currPosition;
  Vector3 movedPosition;
  Vector3 destination;
  float speed;
  bool available;
  std::string strategyName;
  std::string name;
};
#endif
