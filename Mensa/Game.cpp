#include <SFML/Graphics.hpp>
#include "Game.h"
#include "EntitySystem.h"

void Game::Initialize()
{
    InitializeGameSystems();
}

void Game::InitializeGameSystems()
{
    std::shared_ptr< Game > sharedThis = shared_from_this();

    m_gameSystems.reserve( 1 );
    m_gameSystems.push_back( std::make_shared<EntitySystem>( sharedThis ) );
}

void Game::Update()
{
    for ( std::shared_ptr< GameSystem >& system : m_gameSystems )
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

template<typename T>
const std::shared_ptr< T >& Game::GetGameSystem()
{
    std::shared_ptr< T > foundSystem;
    for( std::shared_ptr< GameSystem >& system : m_gameSystems )
    {
        foundSystem = dynamic_cast<T>(system);
        if( foundSystem )
        {
            return foundSystem;
        }
    }
}