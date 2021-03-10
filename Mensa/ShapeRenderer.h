#pragma once
#include "EntityComponent.h"
#include <SFML/Graphics.hpp>
#include "GlobalMacros.h"

class ShapeRenderer : public EntityComponent, public std::enable_shared_from_this< ShapeRenderer >
{
    PARENT_TYPE( EntityComponent );

public:
    ShapeRenderer( const std::weak_ptr< ent::Entity >& owner, const std::shared_ptr< Game >& gameInstnace );

    virtual void Initialize() override;

    void SetDrawOrder( int drawOrder );
    int GetDrawOrder();

    void Draw( sf::RenderWindow& window );

    template<typename T, typename... Args >
    std::shared_ptr< T > SetShapeType( const Args&... arg );

    template<typename T>
    std::shared_ptr< T > GetShape();
    const std::shared_ptr< sf::Shape >& GetShape();

private:
    int m_drawOrder;
    std::shared_ptr< sf::Shape > m_shape;
};

template<typename T, typename... Args >
std::shared_ptr< T > ShapeRenderer::SetShapeType( const Args&... arg )
{
    m_shape = std::make_shared< T >( arg... );

    return std::dynamic_pointer_cast<T>(m_shape);
}

template<typename T>
std::shared_ptr< T > ShapeRenderer::GetShape()
{
    return std::dynamic_pointer_cast<T>(m_shape);
}
