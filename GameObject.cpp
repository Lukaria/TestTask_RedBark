#include "stdafx.h"
#include "GameObject.h"


void GameObject::BoundCollision() {
	if (pos.x < 0 || pos.x > 974 - this->collider.getSize().x) velocity.x = -1 * velocity.x;

	int lower_bound = 60;
	if (texname == "bomb") lower_bound = 580;
	if (pos.y < lower_bound || pos.y > 768  - this->collider.getSize().y) velocity.y = -1 * velocity.y;


}
