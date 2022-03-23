#include "Character.h"
#include "MoveComponent.h"

Character::Character(float x, float y, const char* name, float speed, float maxForce) :
	Agent(x, y, name, maxForce, speed)
{
	m_speed = speed;
	m_firingCooldown = 0.3f;
}

Character::~Character()
{
}

void Character::setVelocity(float x, float y)
{
}

/// <summary>
/// Adds all of the character's components to its components array
/// </summary>
void Character::start()
{

	Actor::start();
}

/// <summary>
/// Called every frame
/// </summary>
/// <param name="deltaTime">The amount of time that has passed between frames</param>
void Character::update(float deltaTime)
{
	Agent::update(deltaTime);
	Actor::update(deltaTime);
}

/// <summary>
/// Called every frame
/// </summary>
void Character::draw()
{
	Actor::draw();
}
