#pragma once
#include <SFML/System/Vector2.hpp>
#include "EntityComponent.h"

class SimpleTransform2D : public EntityComponent
{
public:
    const sf::Vector2f& GetPosition() const;
    const sf::Vector2f& GetScale() const;

    void SetPosition( const sf::Vector2f& position );
    void SetScale( const sf::Vector2f& scale );

private:
    sf::Vector2f m_position;
    sf::Vector2f m_scale;
};