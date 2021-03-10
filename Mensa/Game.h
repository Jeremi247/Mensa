#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include "GameSystem.h"

class Game : public std::enable_shared_from_this< Game >
{
public:
    void Initialize();

    void Update();
    void Draw(sf::RenderWindow& window);

    template<typename T>
    std::shared_ptr< T > GetGameSystem();

private:
    void InitializeGameSystems();

    std::vector<std::shared_ptr<GameSystem>> m_gameSystems;
};


template<typename T>
std::shared_ptr< T > Game::GetGameSystem()
{
    std::shared_ptr< T > foundSystem;
    for( std::shared_ptr< GameSystem >& system : m_gameSystems )
    {
        foundSystem = std::dynamic_pointer_cast<T>(system);
        if( foundSystem )
        {
            return foundSystem;
        }
    }

    return nullptr;
}