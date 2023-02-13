#pragma once
#include "GameObject.h"
#include <vector>
#include <memory>
#include "Target.h"
#include "Ball.h"
#include "Collision.h"

class GameManager
{
private:
	std::vector<Target> targets;
	/*static*/unsigned targetsCounter = 0;
	std::vector<Ball> balls;
	unsigned ballsCounter = 0;
	int timer = 1770;
	Collision collision;
public:

	bool isGameEnded() { return (timer <= 0 || targets.size() <= 0) ? true : false; }

	void Init();

	int getTimer() { return timer; };

	void InitGrid(Target &blueprint, Vector2 startpos, int rows, int columns);

	void Update(float dt);

	void addBall(Ball obj) { 
		obj.setId(ballsCounter++);
		balls.push_back(obj);}

	int getTargets() { return targets.size(); }

	void Draw();

	void addTarget(Target &obj) {
		obj.setId(targetsCounter++);
		targets.push_back(obj); }

};