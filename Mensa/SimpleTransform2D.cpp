#include "SimpleTransform2D.h"

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