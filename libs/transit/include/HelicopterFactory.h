#ifndef HELICOPTER_FACTORY_H_
#define HELICOPTER_FACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Helicopter.h"

#include <vector>

/**
 * @brief Method of creating a helicopter entity
 */
class HelicopterFactory : public IEntityFactory {
 public:
    virtual ~HelicopterFactory() {}

    /**
     * @brief Create a helicopter object
     * 
     * @param[in] entity The specified helicopter entity being created
     */
    IEntity* CreateEntity(JsonObject& entity);
};
#endif
