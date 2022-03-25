#pragma once

class Bullet;
class Actor;
class BulletPool {
public:
	//Initializes variables
	BulletPool(Actor* owner, int count);
	~BulletPool();
	
	//Returns the bullets
	Bullet** getBullets() { return m_bullets; }
	int getCount() { return m_bulletCount; }
	void shootBullet(); //Shoots a disabled bullet
	void enableBullet(Bullet* bullet); //Enables bullets to be updated

	void start(); //Will initialize the bullets

private:
	Bullet** m_bullets; //Array that contains the bullets used
	int m_bulletCount;
	Actor* m_owner;	//The actor that wil shoot the bullets 
};

