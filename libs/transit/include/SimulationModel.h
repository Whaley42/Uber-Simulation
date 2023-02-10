#ifndef SIMULATION_MODEL_H_
#define SIMULATION_MODEL_H_

#include "IController.h"
#include "CompositeFactory.h"
#include "IEntity.h"
#include "graph.h"
using namespace routing;

//--------------------  Model ----------------------------

/**
 * @brief Simulation Model handling the transit simulation and communicating
 *        with the controller
 */
class SimulationModel {
 public:
 /**
  * @brief Used to model a simulation of the physical system
  * 
  * @param[in] controller The controller used to manage the simulation 
  */
  SimulationModel(IController& controller);

 /**
  * @brief Set the graph to be used by the simulation
  * 
  * @param[in] graph The graph to be applied to the simulation 
  */
  void SetGraph(const IGraph* graph) { this->graph = graph; }

 /**
  * @brief Create a simulation entity
  * 
  * @param[in] entity Json object with information on the simulation entity  
  */
  void CreateEntity(JsonObject& entity);

 /**
  * @brief Schedule a trip within the simulation
  * 
  * @param[in] details Json object with details for the trip
  */
  void ScheduleTrip(JsonObject& details);

 /**
  * @brief Update the simulation
  * 
  * @param[in] dt Identifier of the simulation being updated 
  */
  void Update(double dt);

 /**
  * @brief Add a new simulation type
  * 
  * @param[in] factory The simulation type to be produced
  */
  void AddFactory(IEntityFactory* factory);

 protected:
  IController& controller;
  std::vector<IEntity*> entities;
  std::vector<IEntity*> scheduler;
  const IGraph* graph;
  CompositeFactory* compFactory;
};
#endif
