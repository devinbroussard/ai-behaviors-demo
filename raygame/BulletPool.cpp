#include "BulletPool.h"
#include "Actor.h"
#include "Bullet.h"
#include "Engine.h"
#include "MoveComponent.h"


BulletPool::BulletPool(Actor* owner, int count) {
	m_owner = owner;
	m_bullets = nullptr;
	m_bulletCount = count;
}

void BulletPool::shootBullet() {
	for (int i = 0; i < m_bulletCount; i++) {
		if (!m_bullets[i]->isEnabled()) {
			m_bullets[i]->shoot();
		}
	}
}

void BulletPool::enableBullet(Bullet* bullet) {
	for (int i = 0; i < m_bulletCount; i++) {
		if (bullet == m_bullets[i])
			m_bullets[i]->enable();
	}
}

void BulletPool::start() {
	Bullet** m_bullets = new Bullet* [m_bulletCount];

	for (int i = 0; i < m_bulletCount; i++) {
		Bullet* bullet = new Bullet(m_owner);
		m_bullets[i] = bullet;
		m_bullets[i]->start();
		Engine::getCurrentScene()->addActor(bullet);
	}
}
