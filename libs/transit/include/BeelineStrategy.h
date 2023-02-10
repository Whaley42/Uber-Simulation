#ifndef BEELINE_H_
#define BEELINE_H_

#include "math/vector3.h"
#include <vector>
#include "IStrategy.h"
#include "IEntity.h"

/**
 * @brief Inherits from IStrategy, using a Beeline method based
 *        on a specified position and destination. 
 */
class BeelineStrategy : public IStrategy {
 public:
   /**
    * @brief The method of direct movement from the entity's current position
    *        to the end destination
    * 
    * @param[in] position The entity's current position
    * @param[in] destination The entity's desired end position 
    */
    BeelineStrategy(Vector3 position, Vector3 destination);
    ~BeelineStrategy();

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
    Vector3 position;
    Vector3 destination;
};
#endif
