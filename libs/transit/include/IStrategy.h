#ifndef ISTRATEGY_H_
#define ISTRATEGY_H_

#include <vector>
#include "graph.h"
#include "IEntity.h"

using namespace routing;

/**
 * @brief Abstract controller class for our Transit Service, using the 
 *        Model View Controller Pattern       
 */
class IStrategy {
 public:
   /**
    * @brief Move the entity to a desired position
    * 
    * @param[in] entity The object being moved
    * @param[in] dt End goal/position of the entity  
    */
    virtual void Move(IEntity* entity, double dt) = 0;

   /**
    * @brief Boolean representing if the desired movement is completed
    */
    virtual bool IsCompleted() = 0;

 protected:
    const IGraph* graph;
};
#endif
