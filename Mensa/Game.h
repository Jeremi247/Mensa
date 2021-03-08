#pragma once
#include "GameSystem.h"

class Game
{
public:
    void Initialize();

    void Update();
    void Draw(sf::RenderWindow& window);

private:
    std::vector<std::shared_ptr<GameSystem>> m_systems;
};