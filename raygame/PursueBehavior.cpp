#include "PursueBehavior.h"
#include "Transform2D.h"
#include "Actor.h"
#include <Vector2.h>
#include "MoveComponent.h"

PursueBehavior::PursueBehavior(Actor* target, float force) 
	: SteeringComponent(target) {
	m_target = target;
	m_seekForce = force;
}

MathLibrary::Vector2 PursueBehavior::calculateForce(float deltaTime)
{	
	//Calculating future position of target
	MoveComponent* targetComp = getTarget()->getComponent<MoveComponent>();
	MathLibrary::Vector2 futurePosition = getTarget()->getTransform()->getWorldPosition() + targetComp->getVelocity();

	//Seeks the future position of the target
	MathLibrary::Vector2 direction =
		(futurePosition - getOwner()->getTransform()->getWorldPosition()).getNormalized() * m_seekForce;

	MoveComponent* moveComponent = getOwner()->getComponent<MoveComponent>();

	MathLibrary::Vector2 newVelocity = direction - moveComponent->getVelocity();

	//moveComponent->setVelocity(moveComponent->getVelocity() + newVelocity * deltaTime);
	return newVelocity; //Returns the velocity
}