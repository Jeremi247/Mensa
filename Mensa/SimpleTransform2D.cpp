#include "SimpleTransform2D.h"

SimpleTransform2D::SimpleTransform2D( const std::weak_ptr< ent::Entity >& owner, const std::shared_ptr< Game >& gameInstnace )
    : TBaseClass( owner, gameInstnace )
    , m_position( 0.f, 0.f )
    , m_rotation( 0.f )
    , m_scale( 1.f, 1.f )
{

}

const sf::Vector2f& SimpleTransform2D::GetPosition() const
{
    return m_position;
}

const sf::Vector2f& SimpleTransform2D::GetScale() const
{
    return m_scale;
}

void SimpleTransform2D::SetPosition( const sf::Vector2f& position )
{
    m_position = position;
}

void SimpleTransform2D::SetScale( const sf::Vector2f& scale )
{
    m_scale = scale;
}

void SimpleTransform2D::SetRotation( float angle )
{
    m_rotation = angle;
}

float SimpleTransform2D::GetRotation()
{
    return m_rotation;
}