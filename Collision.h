#pragma once
#include "GameObject.h"
class Collision
{
public:
	void ResolveCollision(GameObject& go1, GameObject& go2);

	bool isCollide(Collider co1, Collider co2) const;

	Vector2 getNormal(GameObject& go1, GameObject& go2) const;

};

