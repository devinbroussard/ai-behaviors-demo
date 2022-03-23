#include "Player.h"
#include "InputComponent.h"
#include <Vector2.h>
#include "MoveComponent.h"

Player::Player(float x, float y, const char* name, float speed, int maxHealth, float maxForce) :
	Character::Character(x, y, name, speed, maxHealth, maxForce)
{
}

void Player::start()
{
	// Set spawn point
	//Set move speed
	//Set position clamps
	Agent::start();
	Character::start();
	m_inputComponent = dynamic_cast<InputComponent*>(addComponent(new InputComponent(this)));
	
}

void Player::update(float deltaTime)
{
	MoveComponent* moveComponent = getComponent<MoveComponent>();
	moveComponent->setVelocity(m_inputComponent->getMoveAxis() * Character::getSpeed());
	Character::update(deltaTime);
}

void Player::draw() {
	MathLibrary::Vector2 position = getTransform()->getWorldPosition();
	MathLibrary::Vector2 forwardPos = position + (getTransform()->getForward() * 50);

	RAYLIB_H::DrawCircle(position.x, position.y, getTransform()->getScale().x, GREEN);
	RAYLIB_H::DrawLine(position.x, position.y, forwardPos.x, forwardPos.y, BLACK);
}
