#include "IdleDecision.h"
#include "EvadeBehavior.h"
#include "WanderBehavior.h"
#include "PursueBehavior.h"
#include "Agent.h"

void IdleDecision::makeDecision(Agent* agent, float deltaTime) {
	WanderBehavior* wander = agent->getComponent<WanderBehavior>();
	if (wander) wander->setForce(0);

	EvadeBehavior* seek = agent->getComponent<EvadeBehavior>();
	if (seek) seek->setForce(0);

	EvadeBehavior* flee = agent->getComponent<EvadeBehavior>();
	if (flee) flee->setForce(0);
}
