#pragma once
#include <memory>

class Game;

class GameSystem
{
public:
    GameSystem( const std::shared_ptr< Game >& gameInstance );

    virtual void Update() = 0;

protected:
    const std::shared_ptr< Game >& GetGame();

private:
    std::shared_ptr< Game > m_gameInstance;
};