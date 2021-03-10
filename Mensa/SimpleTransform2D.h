#pragma once
#include <SFML/System/Vector2.hpp>
#include "EntityComponent.h"
#include "GlobalMacros.h"

class SimpleTransform2D : public EntityComponent
{
    PARENT_TYPE( EntityComponent );

public:
    SimpleTransform2D( const std::weak_ptr< ent::Entity >& owner, const std::shared_ptr< Game >& gameInstnace );

    void SetPosition( const sf::Vector2f& position );
    const sf::Vector2f& GetPosition() const;

    void SetScale( const sf::Vector2f& scale );
    const sf::Vector2f& GetScale() const;

    void SetRotation( float angle );
    float GetRotation();

private:
    sf::Vector2f m_position;
    sf::Vector2f m_scale;
    float m_rotation;
};