#pragma once
#include "GameSystem.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <map>
#include "GlobalMacros.h"

namespace sf
{
    class Shape;
}

class ShapeRenderer;

class RenderingSystem : public GameSystem
{
    PARENT_TYPE( GameSystem );

    using ShapesMap = std::map< int, std::vector< std::shared_ptr< ShapeRenderer > > >;

public:
    virtual void Draw( sf::RenderWindow& window ) override;
    void Register( const std::weak_ptr< ShapeRenderer >& component );

private:
    void GatherKeysAndShapes( std::vector< int >& outKeys, ShapesMap& outMap );

    std::vector< std::weak_ptr< ShapeRenderer > > m_registeredRenderers;
};