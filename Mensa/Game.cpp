#include <SFML/Graphics.hpp>
#include "Game.h"
#include "EntitySystem.h"
#include "RenderingSystem.h"
#include "Player.h"

void Game::Initialize()
{
    InitializeGameSystems();
    GetGameSystem< ent::EntitySystem >()->SpawnEntity< Player >();
}

void Game::InitializeGameSystems()
{
    std::shared_ptr< Game > sharedThis = shared_from_this();

    m_gameSystems.reserve( 2 );
    m_gameSystems.push_back( std::make_shared<ent::EntitySystem>( sharedThis ) );
    m_gameSystems.push_back( std::make_shared<RenderingSystem>( sharedThis ) );
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
    window.clear();

    for( const std::shared_ptr< GameSystem >& system : m_gameSystems )
    {
        system->Draw( window );
    }

    window.display();
}
