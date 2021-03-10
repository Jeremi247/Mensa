#include "EntityComponent.h"

EntityComponent::EntityComponent( const std::weak_ptr< ent::Entity >& owner, const std::shared_ptr< Game >& gameInstnace )
    : m_owner( owner )
    , m_gameInstance( gameInstnace )
{
}

const std::shared_ptr< Game >& EntityComponent::GetGameInstance()
{
    return m_gameInstance;
}

std::shared_ptr< ent::Entity > EntityComponent::GetOwner()
{
    return m_owner.lock();
}