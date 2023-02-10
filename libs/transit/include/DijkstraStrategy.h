#ifndef Dijkstra_STRATEGY_H_
#define Dijkstra_STRATEGY_H_

#include "math/vector3.h"
#include <vector>
#include "IStrategy.h"
#include "IEntity.h"

/**
 * @brief Inherits from IStrategy, using the Dijkstra strategy based
 *        on a specified position and destination. 
 */
class DijkstraStrategy : public IStrategy {
 public:
   /**
    * @brief The method of movement from the entity's current position
    *        to the end destination using a Dijkstra algorithm
    * 
    * @param[in] position The entity's current position
    * @param[in] desination The entity's desired end position
    * @param[in] graph The graph of routes used for Dijkstra calculations
    */
    DijkstraStrategy(Vector3 position, Vector3 destination,
    const IGraph* graph);
    ~DijkstraStrategy();

   /**
    * @brief Move the entity to a desired position
    * 
    * @param[in] entity The object being moved
    * @param[in] dt End goal/position of the entity  
    */
    void Move(IEntity* entity, double dt);

   /**
    * @brief Boolean representing if the desired movement is completed
    */
    bool IsCompleted();

 private:
    std::vector<std::vector<float>> path;
    int currentIndex;
    int maxIndex;
};
#endif
