#include <SFML/Graphics.hpp>
#include "Game.h"
#include "EntitySystem.h"

void Game::Initialize()
{
    m_systems.reserve( 1 );
    m_systems.push_back( std::make_shared<EntitySystem>() );
}

void Game::Update()
{
    for ( std::shared_ptr< GameSystem >& system : m_systems )
    {
        system->Update();
    }
}

void Game::Draw( sf::RenderWindow& window )
{
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    window.clear();
    window.draw(shape);
    window.display();
}