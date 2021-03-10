#pragma once
#include <SFML/Graphics/Transform.hpp>
#include <vector>
#include <memory>

class EntityComponent;
class Game;

namespace ent
{
    class Entity : public std::enable_shared_from_this< Entity >
    {
    public:
        Entity( const std::shared_ptr< Game >& gameInstance );

        void Initialize();

        virtual void Start();
        virtual void Update();

        template<typename T, typename... Args>
        std::shared_ptr< T > AddComponent( const Args&... arg );

        template<typename T>
        std::shared_ptr< T > GetComponent();

    private:
        std::vector< std::shared_ptr< EntityComponent > > m_components;
        std::shared_ptr< Game > m_gameInstance;
    };

    template<typename T, typename... Args>
    std::shared_ptr< T > Entity::AddComponent( const Args&... arg )
    {
        std::shared_ptr< T > newComponent = std::make_shared< T >( shared_from_this(), m_gameInstance, arg... );
        newComponent->Initialize();
        m_components.push_back( newComponent );

        return newComponent;
    }

    template<typename T>
    std::shared_ptr< T > Entity::GetComponent()
    {
        std::shared_ptr< T > foundComponent;
        for( std::shared_ptr< EntityComponent >& component : m_components )
        {
            foundComponent = std::dynamic_pointer_cast<T>(component);
            if( foundComponent )
            {
                return foundComponent;
            }
        }

        return nullptr;
    }
}
