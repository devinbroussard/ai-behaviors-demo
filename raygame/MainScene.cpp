#include "MainScene.h"
#include "Actor.h"
#include "Player.h"
#include "Enemy.h"
#include "Scene.h"
#include "Transform2D.h"

void MainScene::start()
{

	Player* player = new Player(200, 200, "player", 100, 10, 200);
	Enemy* enemy = new Enemy(10, 100, "enemy", 400, 10, 400, player);
	player->setTargetActor(enemy);
	player->getTransform()->setScale({ 10, 10 });
	enemy->getTransform()->setScale({ 10, 10 });

	addActor(player);
	addActor(enemy);
}
