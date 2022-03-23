#pragma once
#include "Component.h"
class SeekBehavior;
class WanderBehavior;
class FleeBehavior;

enum State {
	IDLE,
	WANDER,
	SEEK,
	FLEE
};

class EnemyStateMachineComponent :
	public Component {
public:
	EnemyStateMachineComponent();
	~EnemyStateMachineComponent() {}

	State getCurrentState() { return m_currentState; }
	void setCurrentState(State state) { m_currentState = state; }
	SeekBehavior* getSeekComponent() { return m_seekComponent; }
	WanderBehavior* getWanderComponent() { return m_wanderComponent; }
	FleeBehavior* getFleeComponent() { return m_fleeComponent; }
	float getWanderForce() { return m_wanderForce; }
	float getSeekForce() { return m_seekForce; }
	float getFleeForce() { return m_fleeForce; }

	void start() override; 
	virtual void update(float deltaTime) override; 

private:
	State m_currentState;
	SeekBehavior* m_seekComponent;
	WanderBehavior* m_wanderComponent;
	FleeBehavior* m_fleeComponent;
	float m_wanderForce;
	float m_seekForce;
	float m_fleeForce;
	float m_seekRange = 200;
};

