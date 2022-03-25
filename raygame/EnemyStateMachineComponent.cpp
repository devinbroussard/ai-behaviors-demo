#include "EnemyStateMachineComponent.h"
#include "Actor.h"
#include "EvadeBehavior.h"
#include "WanderBehavior.h"
#include "PursueBehavior.h"
#include "Transform2D.h"
#include <Vector2.h>
#include "Bullet.h"

EnemyStateMachineComponent::EnemyStateMachineComponent(Bullet** enemyBullets, int bulletCount) 
	:Component("StateMachineComponent")
{
	m_enemyBullets = enemyBullets;
	m_bulletCount = bulletCount;
}

bool EnemyStateMachineComponent::inRangeOfBullets(Bullet** bullet) {
	float evadeRange = 50;
	*bullet = nullptr;
	float bulletDistance = 100000000;

	for (int i = 0; i < m_bulletCount; i++) {
		if (!m_enemyBullets[i])
			continue;

		MathLibrary::Vector2 ownerPos = getOwner()->getTransform()->getWorldPosition();
		MathLibrary::Vector2 bulletPos = m_enemyBullets[i]->getTransform()->getWorldPosition();
		float distance = (bulletPos - ownerPos).getMagnitude();

		if (distance < evadeRange && distance < bulletDistance && m_enemyBullets[i]->isEnabled()) {
			*bullet = m_enemyBullets[i];
			bulletDistance = distance;
		}
	}

	if (*bullet) return true;
	else {
		bullet = nullptr;
		return false;
	}
}

void EnemyStateMachineComponent::start() {
	m_seekComponent = getOwner()->getComponent<PursueBehavior>();
	m_fleeComponent = getOwner()->getComponent<EvadeBehavior>();
	m_wanderComponent = getOwner()->getComponent<WanderBehavior>();
	m_seekForce = m_seekComponent->getForce();
	m_wanderForce = m_wanderComponent->getForce();
	m_fleeForce = m_fleeComponent->getForce();
	m_currentState = WANDER;
	Component::start();
}

void EnemyStateMachineComponent::update(float deltaTime) {
	MathLibrary::Vector2 targetPos = m_seekComponent->getTarget()->getTransform()->getWorldPosition();
	MathLibrary::Vector2 ownerPos = getOwner()->getTransform()->getWorldPosition();

	float distanceFromTarget = (targetPos - ownerPos).getMagnitude();
	bool targetInRange = distanceFromTarget <= m_seekRange;
	switch (m_currentState) {
	case IDLE:
		m_seekComponent->setForce(0);
		m_wanderComponent->setForce(0);
		m_fleeComponent->setForce(0);

		if (targetInRange)
			setCurrentState(SEEK);

		break;
	case WANDER:
		m_wanderComponent->setForce(m_wanderForce);
		m_seekComponent->setForce(0);
		m_fleeComponent->setForce(0);

		if (targetInRange)
			setCurrentState(SEEK);

		break;
	case SEEK:
		m_wanderComponent->setForce(0);
		m_fleeComponent->setForce(0);
		m_seekComponent->setForce(m_seekForce);

		if (inRangeOfBullets(&m_bulletToEvade))
			setCurrentState(FLEE);
		break;
	case FLEE:
		if (inRangeOfBullets(&m_bulletToEvade))
			m_fleeComponent->setTarget(m_bulletToEvade);
		else setCurrentState(SEEK);

		m_fleeComponent->setForce(m_fleeForce);
		m_seekComponent->setForce(0);
		m_wanderComponent->setForce(0);

		break;
	}
}
