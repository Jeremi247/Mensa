#include "Player.h"
#include "ShapeRenderer.h"
#include "SimpleTransform2D.h"

void Player::Start()
{
    std::shared_ptr<ShapeRenderer> renderer = AddComponent< ShapeRenderer >();

    std::shared_ptr< sf::CircleShape > shape = renderer->SetShapeType< sf::CircleShape >( 50.f );
    shape->setFillColor( sf::Color::Green );
}

void Player::Update()
{
    std::shared_ptr< SimpleTransform2D > transform = GetComponent< SimpleTransform2D >();

    transform->SetPosition( sf::Vector2f( static_cast<int>(transform->GetPosition().x + 1.f) % 500, 0 ) );
}