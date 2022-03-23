#include "Player.h"
#include "InputComponent.h"
#include <Vector2.h>
#include "MoveComponent.h"
#include "SeekBehavior.h"
#include "WanderBehavior.h"
#include "FleeBehavior.h"
#include "PlayerStateMachineComponent.h"

Player::Player(float x, float y, const char* name, float speed, int maxHealth, float maxForce) :
	Character::Character(x, y, name, speed, maxForce) {
}

//Initializes components
void Player::start() {
	Character::start();
	/*
	Character::start();
	SeekBehavior* seekBehavior = new SeekBehavior(m_targetActor, 100);
	addComponent(seekBehavior);
	onAddComponent(seekBehavior);

	WanderBehavior* wanderBehavior = new WanderBehavior(20, 1500, 100);
	addComponent(wanderBehavior);
	onAddComponent(wanderBehavior);

	FleeBehavior* fleeBehavior = new FleeBehavior(m_targetActor, 200);
	addComponent(fleeBehavior);
	onAddComponent(fleeBehavior);

	PlayerStateMachineComponent* stateMachine = new PlayerStateMachineComponent();
	addComponent(stateMachine);*/

	InputComponent* inputComponent = new InputComponent(this);
	addComponent(inputComponent);
}

void Player::update(float deltaTime) {
	Character::update(deltaTime);
}

void Player::draw() {
	MoveComponent* moveComponent = getComponent<MoveComponent>();
	MathLibrary::Vector2 position = getTransform()->getWorldPosition();
	MathLibrary::Vector2 forwardPos = position + (moveComponent->getVelocity().getNormalized() * 50);

	RAYLIB_H::DrawCircle(position.x, position.y, getTransform()->getScale().x, GREEN);
	RAYLIB_H::DrawLine(position.x, position.y, forwardPos.x, forwardPos.y, BLACK);
}
