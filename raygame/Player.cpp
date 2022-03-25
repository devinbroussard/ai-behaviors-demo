#include "Player.h"
#include "InputComponent.h"
#include <Vector2.h>
#include "MoveComponent.h"
#include "EvadeBehavior.h"
#include "WanderBehavior.h"
#include "PursueBehavior.h"
#include "PlayerStateMachineComponent.h"
#include "BulletPool.h"

Player::Player(float x, float y, const char* name, float speed, int maxHealth, float maxForce) :
	Character::Character(x, y, name, speed, maxForce) {
	m_bulletPool = nullptr;
}

//Initializes components
void Player::start() {
	Character::start();
	/*
	Character::start();
	PursueBehavior* seekBehavior = new PursueBehavior(m_targetActor, 100);
	addComponent(seekBehavior);
	onAddComponent(seekBehavior);

	WanderBehavior* wanderBehavior = new WanderBehavior(20, 1500, 100);
	addComponent(wanderBehavior);
	onAddComponent(wanderBehavior);

	EvadeBehavior* fleeBehavior = new EvadeBehavior(m_targetActor, 200);
	addComponent(fleeBehavior);
	onAddComponent(fleeBehavior);

	PlayerStateMachineComponent* stateMachine = new PlayerStateMachineComponent();
	addComponent(stateMachine);*/

	m_inputComponent = new InputComponent(this);
	addComponent(m_inputComponent);
}

void Player::update(float deltaTime) {
	MoveComponent* moveComponent = getComponent<MoveComponent>();
	moveComponent->setVelocity(m_inputComponent->getMoveAxis() * Character::getSpeed());

	if (IsKeyPressed(KEY_SPACE))
		m_bulletPool->shootBullet();

	Character::update(deltaTime);
}

void Player::draw() {
	MathLibrary::Vector2 position = getTransform()->getWorldPosition();
	MathLibrary::Vector2 forwardPos = position + (getTransform()->getForward() * 50);

	RAYLIB_H::DrawCircle(position.x, position.y, getTransform()->getScale().x, GREEN);
	RAYLIB_H::DrawLine(position.x, position.y, forwardPos.x, forwardPos.y, BLACK);
}
