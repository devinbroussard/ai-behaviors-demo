#include "SeekDecision.h"
#include "EvadeBehavior.h"
#include "Enemy.h"
#include "WanderBehavior.h"

void SeekDecision::makeDecision(Agent* agent, float deltaTime) {
	EvadeBehavior* seek = agent->getComponent<EvadeBehavior>();
	WanderBehavior* wander = agent->getComponent<WanderBehavior>();
	Enemy* enemy = dynamic_cast<Enemy*>(agent);

	if (seek) seek->setForce(50);
	if (wander) wander->setForce(0);

	if (enemy) enemy->setIsAggressive(true);
}
