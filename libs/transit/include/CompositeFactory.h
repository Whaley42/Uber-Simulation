#ifndef COMPOSITE_FACTORY_H_
#define COMPOSITE_FACTORY_H_

#include "IEntityFactory.h"

/**
 * @brief Method of creating a factory entity
 */
class CompositeFactory : public IEntityFactory {
 public:
    /**
     * @brief Create a factory object
     * 
     * @param[in] entity The specified factory entity being created
     */
    IEntity* CreateEntity(JsonObject& entity);

    /**
     * @brief Push the factory entity
     * 
     * @param[in] factoryEntity The specified factory entity being added
     */
    void AddFactory(IEntityFactory* factoryEntity);

    virtual ~CompositeFactory();

 private:
    std::vector<IEntityFactory*> componentFactories;
};
#endif
