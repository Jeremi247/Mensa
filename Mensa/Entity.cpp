#include <memory>
#include "Entity.h"
#include "Game.h"
#include "SimpleTransform2D.h"

Entity::Entity( const std::shared_ptr< Game >& gameInstance )
    : m_gameInstance( gameInstance )
{
    AddComponent<SimpleTransform2D>();
}

void Entity::Start()
{
}

void Entity::Update()
{
}

template<typename T, typename... Args>
void Entity::AddComponent( Args... arg )
{
    m_components.push_back( std::make_shared< T >( arg... ) );
}

template<typename T>
const std::shared_ptr< T >& Entity::GetComponent()
{
    std::shared_ptr< T > foundComponent;
    for( std::shared_ptr< EntityComponent >& component : m_components )
    {
        foundComponent = dynamic_cast<T>(component);
        if( foundComponent )
        {
            return foundComponent;
        }
    }
}