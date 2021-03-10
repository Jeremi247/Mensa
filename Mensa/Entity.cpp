#include <memory>
#include "Entity.h"
#include "Game.h"
#include "SimpleTransform2D.h"

namespace ent
{
    Entity::Entity( const std::shared_ptr< Game >& gameInstance )
        : m_gameInstance( gameInstance )
    {
    }

    void Entity::Initialize()
    {
        AddComponent<SimpleTransform2D>();
    }

    void Entity::Start()
    {
    }

    void Entity::Update()
    {
    }
}