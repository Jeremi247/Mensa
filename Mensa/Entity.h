#pragma once
#include <SFML/Graphics/Transform.hpp>
#include <vector>

class EntityComponent;
class Game;

class Entity
{
public:
    Entity( const std::shared_ptr< Game >& gameInstance );

    virtual void Start();
    virtual void Update();

    template<typename T, typename... Args>
    void AddComponent( Args... arg );

    template<typename T> 
    const std::shared_ptr< T >& GetComponent();

private:
    std::vector< std::shared_ptr< EntityComponent > > m_components;
    std::shared_ptr< Game > m_gameInstance;
};