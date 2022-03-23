#include "Enemy.h"
#include "SeekBehavior.h"
#include "WanderBehavior.h"
#include "EnemyStateMachineComponent.h"
#include "FleeBehavior.h"
#include "Transform2D.h"
#include "IdleDecision.h"
#include "SeekDecision.h"
#include "WanderDecision.h"
#include "InRangeDecision.h"
#include "AggressiveDecision.h"
#include "DecisionComponent.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <raylib.h>
#include <Vector2.h>
#include "MoveComponent.h"

Enemy::Enemy(float x, float y, const char* name, float speed, int maxHealth, float maxForce, Actor* targetActor) :
	Character::Character(x, y, name, speed, maxForce)
{
	m_targetActor = targetActor;
}

bool Enemy::getTargetInView()
{
	MathLibrary::Vector2 directionOfTarget = (m_targetActor->getTransform()->getWorldPosition() - getTransform()->getWorldPosition()).getNormalized();
	float distance = (m_targetActor->getTransform()->getWorldPosition() - getTransform()->getWorldPosition()).getMagnitude();
	float coneValue = acos(MathLibrary::Vector2::dotProduct(directionOfTarget, getTransform()->getForward()));

	return (coneValue < 1);
}

bool Enemy::getTargetInRange()
{
	float distance = (m_targetActor->getTransform()->getWorldPosition() - getTransform()->getWorldPosition()).getMagnitude();
	return distance <= 100;
}

void Enemy::start()
{
	Character::start();
	SeekBehavior* seekBehavior = new SeekBehavior(m_targetActor, 120);
	addComponent(seekBehavior);
	onAddComponent(seekBehavior);

	WanderBehavior* wanderBehavior = new WanderBehavior(12, 1500, 100);
	addComponent(wanderBehavior);
	onAddComponent(wanderBehavior);

	FleeBehavior* fleeBehavior = new FleeBehavior(m_targetActor, 150);
	addComponent(fleeBehavior);
	onAddComponent(fleeBehavior);

	//IdleDecision* idleDecision = new IdleDecision();
	//WanderDecision* wanderDecision = new WanderDecision();
	//SeekDecision* seekDecision = new SeekDecision();

	//AggressiveDecision* aggressive = new AggressiveDecision(idleDecision, wanderDecision);
	//InRangeDecision* inRange = new InRangeDecision(aggressive, seekDecision);

	//addComponent(new DecisionComponent(inRange));
	

	EnemyStateMachineComponent* stateMachineComponent = new EnemyStateMachineComponent();
	addComponent(stateMachineComponent);
}

void Enemy::draw() {
	MoveComponent* moveComponent = getComponent<MoveComponent>();
	MathLibrary::Vector2 position = getTransform()->getWorldPosition();
	MathLibrary::Vector2 forwardPos = position + (moveComponent->getVelocity().getNormalized() * 50);

	RAYLIB_H::DrawCircle(position.x, position.y, getTransform()->getScale().x, RED);
	RAYLIB_H::DrawLine(position.x, position.y, forwardPos.x, forwardPos.y, BLACK);
}
