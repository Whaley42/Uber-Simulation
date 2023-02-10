#ifndef ENTITY_H_
#define ENTITY_H_

#include <vector>

#include "graph.h"
#include "math/vector3.h"
#include "util/json.h"



using namespace routing;

/**
 * @brief Represents an entity in the physical system
 */
class IEntity {
 public:
 /**
  * @brief Updates the total number of entities
  */
  IEntity() {
    static int currentId = 0;
    id = currentId;
    currentId++;
  }
  virtual ~IEntity() {}

 /**
  * @brief Get the entity's ID
  * 
  * @return The entity's ID represented by an int
  */
  virtual int GetId() const { return id; }

 /**
  * @brief Get the entity's position
  * 
  * @return The entity's positioning represented as a 3D vector
  */
  virtual Vector3 GetPosition() const = 0;

 /**
  * @brief Get the entity's direction
  * 
  * @return The entity's orientation represented as a 3D vector
  */
  virtual Vector3 GetDirection() const = 0;

 /**
  * @brief Get the entity's destination
  * 
  * @return The entity's goal coordinates represented as a 3D vector
  */
  virtual Vector3 GetDestination() const = 0;

 /**
  * @brief Get the entity's details
  * 
  * @return The json object containing the entity's information
  */
  virtual JsonObject GetDetails() const = 0;

 /**
  * @brief Get the entity's speed
  * 
  * @return The entity's speed represented as a float 
  */
  virtual float GetSpeed() const = 0;

 /**
  * @brief A boolean representing the entity's status
  * 
  * @return Boolean as to whether the entity is in-service
  */
  virtual bool GetAvailability() const {}

 /**
  * @brief Gets the entity's name
  * 
  * @return A string representing the entity's name
  */
  virtual std::string GetName() {}

 /**
  * @brief Get the entity's strategy
  * 
  * @return A string representing the entity's name
  */
  virtual std::string GetStrategyName() {}

 /**
  * @brief Sets the enetity's availability
  * 
  * @param[in] choice Boolean representing whether the entity is in-service
  */
  virtual void SetAvailability(bool choice) {}

 /**
  * @brief Update the specified entity
  * 
  * @param[in] dt The entity to be updated 
  */
  virtual void Update(double dt, std::vector<IEntity*> scheduler) {}

 /**
  * @brief Set the graph which acts as our physical system
  * 
  * @param[in] graph The graph that will represent our physical system 
  */
  void SetGraph(const IGraph* graph) { this->graph = graph; }

 /**
  * @brief Set the entity's position
  * 
  * @param[in] pos The 3D vector that will be used as the entity's position  
  */
  virtual void SetPosition(Vector3 pos_) {}

 /**
  * @brief Set the entity's direction
  * 
  * @param[in] dir The 3D vector that will be used as the entity's direction  
  */
  virtual void SetDirection(Vector3 dir_) {}

 /**
  * @brief Set the entity's destination
  * 
  * @param[in] des The 3D vector that will be used as the entity's destination  
  */
  virtual void SetDestination(Vector3 des_) {}

 /**
  * @brief Set the strategy to be used by the entity
  * 
  * @param[in] strategyName The strategy to be applied to the entity
  */
  virtual void SetStrategyName(std::string strategyName_) {}

 /**
  * @brief Rotate the entity by a desired angle
  * 
  * @param[in] angle The angle to which the entity is rotated   
  */
  virtual void Rotate(double angle) {}

 /**
  * @brief Change the entity's height
  * 
  * @param[in] height The value that the entity's height is changed to   
  */
  virtual void Jump(double height) {}

 protected:
  int id;
  const IGraph* graph;
};
#endif
