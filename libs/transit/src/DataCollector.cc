#include "DataCollector.h"
#include <iostream>


DataCollector& DataCollector::Get(){
        static DataCollector instance;
        return instance;
        
}


void DataCollector::AddObject(IEntity* Entity){
    JsonObject details = Entity->GetDetails();
    std::string name = details["name"];
    
    if(objects.count(name) >0){
        name = name+"-1";
        
    }
    std::string type = details["type"];
    std::string distance = "Distance";
    std::string robots = "Robots";
    
    objects.insert(std::make_pair(name, std::map<std::string, float>()));
    objects[name].insert(make_pair(distance, 0.0));
    if(type == "drone"){
        objects[name].insert(make_pair(robots, 0));
    }
    std::cout<< objects.size() <<std::endl;
}

void DataCollector::SetDistance(Vector3 pos1, Vector3 pos2, std::string name){
    float distance = (pos2 - pos1).Magnitude();
    objects[name]["Distance"] += distance;
    
    
}

void DataCollector::AddRobot(std::string name){
    objects[name]["Robots"] += 1;
}

