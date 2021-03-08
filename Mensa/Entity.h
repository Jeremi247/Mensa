#pragma once
#include <SFML/Graphics/Transform.hpp>

class Entity
{
public:
    virtual void Start();
    virtual void Update();

private:
    sf::Transform m_transform;
};