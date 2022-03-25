#include "WanderDecision.h"
#include "WanderBehavior.h"
#include "EvadeBehavior.h"

void WanderDecision::makeDecision(Agent* agent, float deltaTime) {
	WanderBehavior* wander = agent->getComponent<WanderBehavior>();
	EvadeBehavior* seek = agent->getComponent<EvadeBehavior>();

	if (wander) wander->setForce(200);
	if (seek) seek->setForce(0);
}
