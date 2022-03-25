#include "EvadeBehavior.h"
#include "Transform2D.h"
#include "Actor.h"
#include <Vector2.h>
#include "MoveComponent.h"
#include "SteeringComponent.h"

EvadeBehavior::EvadeBehavior(Actor* target, float fleeForce)
	: SteeringComponent(target) {
	m_target = target;
	m_fleeForce = fleeForce;
}

MathLibrary::Vector2 EvadeBehavior::calculateForce(float deltaTime) {
	MoveComponent* targetComp = getTarget()->getComponent<MoveComponent>();
	MathLibrary::Vector2 futurePosition = getTarget()->getTransform()->getWorldPosition() + targetComp->getVelocity() * 0.1;

	MathLibrary::Vector2 direction =
		(getOwner()->getTransform()->getWorldPosition() - futurePosition).getNormalized() * m_fleeForce;

	MoveComponent* moveComponent = getOwner()->getComponent<MoveComponent>();

	MathLibrary::Vector2 newVelocity = direction - moveComponent->getVelocity();

	//moveComponent->setVelocity(moveComponent->getVelocity() + newVelocity * deltaTime);

	return newVelocity;
}