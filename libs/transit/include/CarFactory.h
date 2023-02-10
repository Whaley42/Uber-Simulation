#ifndef CAR_FACTORY_H_
#define CAR_FACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Car.h"

#include <vector>

/**
 * @brief Method of creating a car entity
 */
class CarFactory : public IEntityFactory {
 public:
    virtual ~CarFactory() {}

    /**
     * @brief Create a car object
     * 
     * @param[in] entity The specified car entity being created
     */
    IEntity* CreateEntity(JsonObject& entity);
};

#endif
