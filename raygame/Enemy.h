#pragma once
#include "Character.h"
class Bullet;

class Enemy :
	public Character
{
public:
	Enemy(float x, float y, const char* name, float speed, int maxHealth, float maxForce, Actor* targetActor);
	~Enemy() {}

	void setEnemyBullets(Bullet** bullets) { m_enemyBullets = bullets; }
	bool getTargetInView();
	bool getTargetInRange();
	bool getIsAggressive() { return m_isAggressive; }
	void setIsAggressive(bool value) { m_isAggressive = value; }

	void start() override; //Initializes any used components
	void draw() override; //Draws this actor to the screen

private:
	bool m_isAggressive;
	Actor* m_targetActor;
	Bullet** m_enemyBullets;
};

