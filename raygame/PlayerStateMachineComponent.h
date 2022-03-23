#pragma once
#include "EnemyStateMachineComponent.h"
class PlayerStateMachineComponent :
	public EnemyStateMachineComponent {
public:
	PlayerStateMachineComponent() { m_fleeRange = 100; }
	~PlayerStateMachineComponent() {}

	void start() override; //Changes the current state of the player
	void update(float deltaTime) override; //Updates the player's state every frame

private:
	//The range that the target must enter for the player to start fleeing
	float m_fleeRange = 100; 
};

