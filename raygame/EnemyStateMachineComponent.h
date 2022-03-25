#pragma once
#include "Component.h"
class PursueBehavior;
class WanderBehavior;
class EvadeBehavior;
class Bullet;

enum State {
	IDLE,
	WANDER,
	SEEK,
	FLEE
};

class EnemyStateMachineComponent :
	public Component {
public:
	EnemyStateMachineComponent(Bullet** enemyBullets, int bulletCount);
	~EnemyStateMachineComponent() {}

	//Returns true if the enemy is in range of any bullets
	bool inRangeOfBullets(Bullet** bullet);
	State getCurrentState() { return m_currentState; }
	void setCurrentState(State state) { m_currentState = state; }
	PursueBehavior* getSeekComponent() { return m_seekComponent; }
	WanderBehavior* getWanderComponent() { return m_wanderComponent; }
	EvadeBehavior* getFleeComponent() { return m_fleeComponent; }
	float getWanderForce() { return m_wanderForce; }
	float getSeekForce() { return m_seekForce; }
	float getFleeForce() { return m_fleeForce; }

	void start() override; 
	virtual void update(float deltaTime) override; 

private:
	Bullet* m_bulletToEvade;
	int m_bulletCount;
	Bullet** m_enemyBullets;
	State m_currentState;
	PursueBehavior* m_seekComponent;
	WanderBehavior* m_wanderComponent;
	EvadeBehavior* m_fleeComponent;
	float m_wanderForce;
	float m_seekForce;
	float m_fleeForce;
	float m_seekRange = 200;
};

