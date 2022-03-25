#pragma once
#include "Component.h"
#include <Vector2.h>
#include "SteeringComponent.h"

class EvadeBehavior :
	public SteeringComponent {
public:
	EvadeBehavior(Actor* target, float fleeForce);
	~EvadeBehavior() {}//Deallocates memory 

	void setTarget(Actor* target) { m_target = target; }
	Actor* getTarget() const { return m_target; }

	void setForce(float force) { m_fleeForce = force; } //Changes the flee force
	float getForce() { return m_fleeForce; } //Returns the flee force

	MathLibrary::Vector2 calculateForce(float deltaTime) override; 

private:
	Actor* m_target;
	float m_fleeForce;
};

