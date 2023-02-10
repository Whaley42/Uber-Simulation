#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "IEntity.h"
#include "util/json.h"

//--------------------  Controller Interface ----------------------------

/// Abstract controller class used in the Transit Service.  Uses the Model View
/// Controller Pattern
/**
 * @brief Abstract controller class used in the Transit Service that uses
 *        the Model View Controller Pattern
 */
class IController {
 public:
  virtual ~IController() {}

  /**
   * @brief Adds an entity to the program
   * 
   * @param[in] entity The entity being added
   */
  virtual void AddEntity(const IEntity& entity) = 0;

  /**
   * @brief Updates an existing entity
   * 
   * @param[in] entity entity being updated
   */
  virtual void UpdateEntity(const IEntity& entity) = 0;

  /**
   * @brief Removes an existing entity
   * 
   * @param[in] id Identifier of the entity being removed
   */
  virtual void RemoveEntity(int id) = 0;

  /**
   * @brief Adds path for a given entity
   * 
   * @param[in] id Identifier of the path
   * @param[in] path The path being added 
   */
  virtual void AddPath(int id,
  const std::vector<std::vector<float> >& path) = 0;

  /**
   * @brief Removes a path from the program
   * 
   * @param[in] id Identifier of the path being removed
   */
  virtual void RemovePath(int id) = 0;

  /**
   * @brief Updates the view 
   * 
   * @param[in] event The event being added to the view
   * @param[in] details The json object containing event information
   */
  virtual void SendEventToView(const std::string& event,
  const JsonObject& details) = 0;
};
#endif
