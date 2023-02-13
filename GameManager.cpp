#include "stdafx.h"
#include "GameManager.h"

void GameManager::Init()
{
	targets.clear();
	targetsCounter = 0;
	balls.clear();
	ballsCounter = 0;

	this->timer = 1770;
	Target target(Vector2{ 200, 200 }, 1);
	target.setCollider(Vector2{ 45, 45 });

	target.setVelocity(Vector2{ 150 , 00});
	InitGrid(target, Vector2{ 150, 300 }, 3, 5);

	Target bomb(Vector2{ 200, 200 }, 2);
	bomb.setVelocity(Vector2{ 0, -100 });
	bomb.setTexsize(Vector2{ 50, 50 });
	bomb.setTexture("bomb");
	bomb.setCollider(Vector2{ 35, 35 });
	InitGrid(bomb, Vector2{ 120, 700 }, 1, 8);
}


void GameManager::InitGrid(Target &blueprint, Vector2 startpos, int rows, int columns){
	try {
		float offsetX = 100, offsetY =	100;
		for (int i = 0; i < columns; i++) {
			for (int j = 0; j < rows; j++) {
				Target *go = new Target(blueprint);
				go->setPos(Vector2{ startpos.x + i * offsetX, startpos.y + j * offsetY });
				addTarget(*go);				
				delete go;
			}
		}		
	}
	catch (...) {
		std::cout << "InitGrid Failed" << std::endl;
	}

}

void GameManager::Update(float dt)
{
	try {
		for (auto iter = balls.begin(); iter != balls.end();) {
			for (int j = 0; j < targets.size(); j++) {
				collision.ResolveCollision(*iter, targets[j]);
			}
			if (iter->Update(dt) != -1) iter = balls.erase(iter);
			else  ++iter;
		}

		for (auto iter = targets.begin(); iter != targets.end();) {
			for (auto inner_iter = targets.begin(); inner_iter != targets.end(); ++inner_iter)
			{
				if (iter == inner_iter) continue;
				collision.ResolveCollision(*iter, *inner_iter);
			}

			if (iter->Update(dt) != -1) iter = targets.erase(iter);
			else ++iter;
		}

		if (!isGameEnded())timer -= dt;
	}
	catch (...) {
		std::cout << "Manager.Update() Failed" << std::endl;
	}
}

void GameManager::Draw()
{
	for (auto& obj : targets) obj.Draw();
	for (auto& obj : balls) obj.Draw();
}