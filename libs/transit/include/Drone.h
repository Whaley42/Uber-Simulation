#ifndef DRONE_H_
#define DRONE_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"
#include <string>

/**
 * @brief Represents a drone in the physical system
 */
class Drone : public IEntity {
 public:
 /**
  * @brief Drone created from a json object
  * 
  * @param[in] obj The json object containing the drone's information
  */
  Drone(JsonObject& obj);

 /**
  * @brief Destructor
  */
  ~Drone();

 /**
  * @brief Get the drone's speed
  * 
  * @return The drone's speed represented as a float 
  */
  float GetSpeed() const { return speed; }

 /**
  * @brief Get the drone's position
  * 
  * @return The drone's positioning represented as a 3D vector
  */
  Vector3 GetPosition() const { return position; }

 /**
  * @brief Get the drone's direction
  * 
  * @return The drone's orientation represented as a 3D vector
  */
  Vector3 GetDirection() const { return direction; }

 /**
  * @brief Get the drone's destination
  * 
  * @return The drone's goal coordinates represented as a 3D vector
  */
  Vector3 GetDestination() const { return destination; }

 /**
  * @brief Get the drone's details
  * 
  * @return The json object containing the drone's information
  */
  JsonObject GetDetails() const { return details; }

 /**
  * @brief A boolean representing the drone's status
  * 
  * @return Boolean as to whether the drone is in-service
  */
  bool GetAvailability() const { return available; }

 /**
  * @brief Get the nearest entity 
  */
  void GetNearestEntity(std::vector<IEntity*> scheduler);

 /**
  * @brief Update the drone's position
  * 
  * @param[in] dt Update the drone entity
  */
  void Update(double dt, std::vector<IEntity*> scheduler);

 /**
  * @brief Set the drone's position
  * 
  * @param[in] pos The 3D vector that will be used as the drone's position  
  */
  void SetPosition(Vector3 pos_) { position = pos_; }

 /**
  * @brief Set the drone's direction
  * 
  * @param[in] dir The 3D vector that will be used as the drone's direction  
  */
  void SetDirection(Vector3 dir_) { direction = dir_; }

 /**
  * @brief Set the drone's destination
  * 
  * @param[in] des The 3D vector that will be used as the drone's destination  
  */
  void SetDestination(Vector3 des_) { destination = des_; }

 /**
  * @brief Rotate the drone by a desired angle
  * 
  * @param[in] angle The angle to which the drone is rotated   
  */
  void Rotate(double angle);

 /**
  * @brief Change the drone's height
  * 
  * @param[in] height The value that the drone's height is changed to   
  */
  void Jump(double height);

 /**
  * @brief The removal of the copy construct and assignment operator
  * 
  * @param[in] drone The drone being removed so it cannot be copied
  */
  Drone(const Drone& drone) = delete;
  Drone& operator=(const Drone& drone) = delete;

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  Vector3 currPosition;
  Vector3 movedPosition;
  float jumpHeight = 0;
  bool goUp = true;  // jump helper
  Vector3 destination;
  float speed;
  bool available;
  bool pickedUp;
  std::string strategyName;
  IEntity* nearestEntity = NULL;
  IStrategy* toTargetPosStrategy = NULL;
  IStrategy* toTargetDestStrategy = NULL;
  std::string name = "None";
};
#endif
