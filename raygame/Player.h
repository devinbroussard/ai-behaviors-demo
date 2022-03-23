#pragma once
#include "Character.h"
class InputComponent;

class Player :
	public Character
{
public:
	Player(float x, float y, const char* name, float speed, int maxHealth, float maxForce);
	~Player() {};

	//Used to set the target acotr
	void setTargetActor(Actor* actor) { m_targetActor = actor; }
	//Used to return the target actor
	Actor* getTargetActor() { return m_targetActor; }

	void fireBullet(float deltaTime);
	void start() override;
	void update(float deltaTime) override;
	void draw() override; //Draws this actor onto the screen
private:
	InputComponent* m_inputComponent;
	Actor* m_targetActor; //The actor that this actor will flee from
};

