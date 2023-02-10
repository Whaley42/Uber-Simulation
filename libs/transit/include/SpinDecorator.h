#ifndef SPIN_DECORATOR_H_
#define SPIN_DECORATOR_H_

#include <vector>

#include "CelebrationDecorator.h"
#include "IStrategy.h"

/**
 * @brief Decorator inherting from IStrategy       
 */
class SpinDecorator : public CelebrationDecorator {
 public:
 /**
  * @brief Assigns the strategy
  *  
  * @param[in] strategy The strategy to be applied      
  */
  SpinDecorator(IStrategy* strategy_) : CelebrationDecorator(strategy_) {}

 /**
  * @brief Boolean representing if the desired action is completed
  */
  bool IsCompleted();

 /**
  * @brief Move the entity to a desired position
  * 
  * @param[in] entity The object being moved
  * @param[in] dt End goal/position of the entity  
  */
  void Move(IEntity* entity, double dt);
};
#endif
