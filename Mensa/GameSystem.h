#pragma once
#include <memory>

namespace sf
{
    class RenderWindow;
}

class Game;

class GameSystem
{
public:
    GameSystem( const std::shared_ptr< Game >& gameInstance );

    virtual void Update() {};
    virtual void Draw( sf::RenderWindow& window ) {};

    virtual ~GameSystem() {};

protected:
    const std::shared_ptr< Game >& GetGame();

private:
    std::shared_ptr< Game > m_gameInstance;
};