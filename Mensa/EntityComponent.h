#pragma once
#include "Entity.h"

class EntityComponent
{
public:
    EntityComponent( const std::weak_ptr< ent::Entity >& owner, const std::shared_ptr< Game >& gameInstnace );

    virtual void Initialize() {};

    virtual ~EntityComponent() {};

protected:
    std::shared_ptr< ent::Entity > GetOwner();
    const std::shared_ptr< Game >& GetGameInstance();

private:
    std::weak_ptr< ent::Entity > m_owner;
    std::shared_ptr< Game > m_gameInstance;
};