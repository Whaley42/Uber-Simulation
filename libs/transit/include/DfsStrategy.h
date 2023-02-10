#ifndef DFS_STRATEGY_H_
#define DFS_STRATEGY_H_

#include "math/vector3.h"
#include <vector>
#include "IStrategy.h"
#include "IEntity.h"

/**
 * @brief Inherits from IStrategy, using a DFS search based
 *        on a specified position and destination. 
 */
class DfsStrategy : public IStrategy {
 public:
   /**
    * @brief The method of movement from the entity's current position
    *        to the end destination using a depth-first search
    * 
    * @param[in] position The entity's current position
    * @param[in] destination The entity's desired end position
    * @param[in] graph The graph of routes used for DFS calculations
    */
    DfsStrategy(Vector3 position, Vector3 destination, const IGraph* graph);
    ~DfsStrategy();

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
