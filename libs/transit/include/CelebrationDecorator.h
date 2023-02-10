#ifndef CELEBRATION_DECORATOR_H_
#define CELEBRATION_DECORATOR_H_

#include <vector>

#include "IStrategy.h"

/**
 * @brief Decorator for designating a specific strategy,
 *        inherted from IStrategy
 */
class CelebrationDecorator : public IStrategy {
 public:
 /**
  * @brief Assigns the strategy
  *  
  * @param[in] strategy The strategy to be applied      
  */
  CelebrationDecorator(IStrategy *strategy_) {
    strategy = strategy_;
    time = 0;
  }

 /**
  * @brief Move the entity to a desired position
  * 
  * @param[in] entity The object being moved
  * @param[in] dt End goal/position of the entity  
  */
  void Move(IEntity *entity, double dt);

 /**
  * @brief Boolean representing if the desired action is completed
  */
  bool IsCompleted();

 protected:
  IStrategy *strategy;
  float time;
};
#endif
