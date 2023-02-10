#ifndef I_ENTITY_FACTORY_H_
#define I_ENTITY_FACTORY_H_

#include "util/json.h"

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Drone.h"

/**
 * @brief Method of creating an entity
 */
class IEntityFactory {
 public:
    virtual ~IEntityFactory() {}

    /**
     * @brief Create an entity
     * 
     * @param[in] entity The specified entity being created
     */
    virtual IEntity* CreateEntity(JsonObject& entity) = 0;
};
#endif
