#ifndef ROBOT_FACTORY_H_
#define ROBOT_FACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Robot.h"

#include <vector>

/**
 * @brief Method of creating a robot entity
 */
class RobotFactory : public IEntityFactory {
 public:
    /**
     * @brief Create a robot object
     * 
     * @param[in] entity The specified robot entity being created
     */
    IEntity* CreateEntity(JsonObject& entity);
};
#endif
