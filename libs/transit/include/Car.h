#ifndef CAR_H
#define CAR_H

#include <vector>

#include "IEntity.h"
#include "math/vector3.h"
#include "util/json.h"
#include "IStrategy.h"

/**
 * @brief Represents a car in the physical system
 */
class Car : public IEntity {
 public:
 /**
  * @brief Car created from a json object
  * 
  * @param[in] obj The json object containing the car's information
  */
  Car(JsonObject& obj);

 /**
  * @brief Destructor
  */
  ~Car() override = default;

 /**
  * @brief Get the car's position
  * 
  * @return The car's positioning represented as a 3D vector
  */
  Vector3 GetPosition() const { return position; }

 /**
  * @brief Get the car's direction
  * 
  * @return The car's orientation represented as a 3D vector
  */
  Vector3 GetDirection() const { return direction; }

 /**
  * @brief Get the car's destination
  * 
  * @return The car's goal coordinates represented as a 3D vector
  */
  Vector3 GetDestination() const { return destination; }

 /**
  * @brief Get the car's details
  * 
  * @return The json object containing the car's information
  */
  JsonObject GetDetails() const override;

 /**
  * @brief Get the car's speed
  * 
  * @return The car's speed represented as a float 
  */
  float GetSpeed() const { return speed; }

 /**
  * @brief Set the car's position
  * 
  * @param[in] pos The 3D vector that will be used as the car's position  
  */
  void SetPosition(Vector3 pos_) { position = pos_; }

 /**
  * @brief Set the car's direction
  * 
  * @param[in] dir The 3D vector that will be used as the car's direction  
  */
  void SetDirection(Vector3 dir_) { direction = dir_; }

 /**
  * @brief Set the car's destination
  * 
  * @param[in] des The 3D vector that will be used as the car's destination  
  */
  void SetDestination(Vector3 des_) { destination = des_; }

 /**
  * @brief Rotate the car by a desired angle
  * 
  * @param[in] angle The angle to which the car is rotated   
  */
  void Rotate(double angle);

 /**
  * @brief Update the car's position
  * 
  * @param[in] dt Update the car entity
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
  * @brief Sets a new destination for the car entity
  */
  void SetNewDestination();

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  Vector3 currPosition;
  Vector3 movedPosition;
  Vector3 destination;
  IStrategy* strategy = NULL;
  float speed;
  std::string name;
};

#endif  // CAR_H
