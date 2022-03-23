#include "PlayerStateMachineComponent.h"
#include <Vector2.h>
#include "FleeBehavior.h"
#include "WanderBehavior.h"
#include "SeekBehavior.h"
#include "Actor.h"
#include "Transform2D.h"

void PlayerStateMachineComponent::start() {
	EnemyStateMachineComponent::start();
	setCurrentState(WANDER);
}

void PlayerStateMachineComponent::update(float deltaTime) {
	MathLibrary::Vector2 targetPos = getFleeComponent()->getTarget()->getTransform()->getWorldPosition();
	MathLibrary::Vector2 ownerPos = getOwner()->getTransform()->getWorldPosition();

	float distanceFromTarget = (targetPos - ownerPos).getMagnitude();
	bool targetInRange = distanceFromTarget <= m_fleeRange;

	switch (getCurrentState()) {
		case IDLE: {
			getSeekComponent()->setForce(0);
			getWanderComponent()->setForce(0);
			getFleeComponent()->setForce(0);
		}
		break;
		case WANDER: {
			getWanderComponent()->setForce(getWanderForce());
			getSeekComponent()->setForce(0);
			getFleeComponent()->setForce(0);
			if (targetInRange) setCurrentState(FLEE);
		}
		break;
		case SEEK: {
			getWanderComponent()->setForce(0);
			getFleeComponent()->setForce(0);
			getSeekComponent()->setForce(getSeekForce());
		}
		break;
		case FLEE: {
			getWanderComponent()->setForce(0);
			getFleeComponent()->setForce(getFleeForce());
			getSeekComponent()->setForce(0);

			if (!targetInRange) setCurrentState(WANDER);
		}
		break;
	}
}