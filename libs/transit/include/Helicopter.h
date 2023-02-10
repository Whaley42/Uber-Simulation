#ifndef HELICOPTER_H
#define HELICOPTER_H

#include <vector>

#include "IEntity.h"
#include "math/vector3.h"
#include "util/json.h"
#include "IStrategy.h"

/**
 * @brief Represents a helicopter in the physical system
 */ 
class Helicopter : public IEntity {
 public:
 /**
  * @brief Helicopter created from a json object
  * 
  * @param[in] obj The json object containing the helicopter's information
  */
  Helicopter(JsonObject& obj);

 /**
  * @brief Destructor
  */
  ~Helicopter() override = default;

 /**
  * @brief Get the helicopter's position
  * 
  * @return The helicopter's positioning represented as a 3D vector
  */
  Vector3 GetPosition() const { return position; }

 /**
  * @brief Get the helicopter's direction
  * 
  * @return The helicopter's orientation represented as a 3D vector
  */
  Vector3 GetDirection() const { return direction; }

 /**
  * @brief Get the helicopter's destination
  * 
  * @return The helicopter's goal coordinates represented as a 3D vector
  */
  Vector3 GetDestination() const { return destination; }

 /**
  * @brief Get the helicopter's details
  * 
  * @return The json object containing the helicopter's information
  */
  JsonObject GetDetails() const override;

 /**
  * @brief Get the helicopter's speed
  * 
  * @return The helicopter's speed represented as a float 
  */
  float GetSpeed() const { return speed; }

 /**
  * @brief Set the helicopter's position
  * 
  * @param[in] pos The 3D vector that will be used as the helicopter's position  
  */
  void SetPosition(Vector3 pos_) { position = pos_; }

 /**
  * @brief Set the helicopter's direction
  * 
  * @param[in] dir The 3D vector that will be used as the helicopter's direction  
  */ 
  void SetDirection(Vector3 dir_) { direction = dir_; }

 /**
  * @brief Set the helicopter's destination
  * 
  * @param[in] des The 3D vector that will be used as the helicopter's destination  
  */
  void SetDestination(Vector3 des_) { destination = des_; }

 /**
  * @brief Rotate the helicopter by a desired angle
  * 
  * @param[in] angle The angle to which the helicopter is rotated   
  */
  void Rotate(double angle);

 /**
  * @brief Update the helicopter's position
  * 
  * @param[in] dt Update the helicopter entity
  */
  void Update(double dt, std::vector<IEntity*> scheduler);

 /**
  * @brief Get a random float
  * 
  * @param[in] Min The floor (lowest) potential float
  * @param[in] Max The ceiling (highest) potential float
  * 
  * @return The random float generated 
  */
  float Random(float Min, float Max);

 /**
  * @brief Sets a new destination for the helicopter entity
  */
  void SetNewDestination();

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  Vector3 destination;
  Vector3 currPosition;
  Vector3 movedPosition;
  IStrategy* strategy = NULL;
  float speed;
  // DataCollector& dc = DataCollector::Get();
  std::string name = "None";
};
#endif
