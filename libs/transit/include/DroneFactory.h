#ifndef DRONE_FACTORY_H_
#define DRONE_FACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Drone.h"

#include <vector>

/**
 * @brief Method of creating a car entity
 */
class DroneFactory : public IEntityFactory {
 public:
    virtual ~DroneFactory() {}

    /**
     * @brief Create a car object
     * 
     * @param[in] entity The specified car entity being created
     */
    IEntity* CreateEntity(JsonObject& entity);
};
#endif
