#pragma once
#include "Character.h"
class InputComponent;

class Player :
	public Character
{
public:
	Player(float x, float y, const char* name, float speed, int maxHealth, float maxForce);
	~Player() {};

	void start() override;
	void update(float deltaTime) override;
	void draw() override; //Draws this actor onto the screen
private:
	InputComponent* m_inputComponent;
};

