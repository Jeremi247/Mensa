#include "ShapeRenderer.h"
#include "Game.h"
#include "RenderingSystem.h"
#include "SimpleTransform2D.h"

ShapeRenderer::ShapeRenderer( const std::weak_ptr< ent::Entity >& owner, const std::shared_ptr< Game >& gameInstnace )
    : TBaseClass( owner, gameInstnace )
    , m_drawOrder( 0 )
{
}

void ShapeRenderer::Initialize()
{
    const std::shared_ptr< Game >& gameInstance = GetGameInstance();

    std::shared_ptr< RenderingSystem > renderingSystem = gameInstance->GetGameSystem< RenderingSystem >();

    std::shared_ptr< ShapeRenderer > sharedThis = shared_from_this();
    renderingSystem->Register( sharedThis );
}

void ShapeRenderer::SetDrawOrder( int drawOrder )
{
    m_drawOrder = drawOrder;
}

int ShapeRenderer::GetDrawOrder()
{
    return m_drawOrder;
}

void ShapeRenderer::Draw( sf::RenderWindow& window )
{
    const std::shared_ptr< SimpleTransform2D >& transform = GetOwner()->GetComponent< SimpleTransform2D >();
    
    const std::shared_ptr< sf::Shape >& shape = GetShape();
    shape->setPosition( transform->GetPosition() );
    shape->setScale( transform->GetScale() );
    shape->setRotation( transform->GetRotation() );

    window.draw( *shape.get() );
}

const std::shared_ptr< sf::Shape >& ShapeRenderer::GetShape()
{
    return m_shape;
}