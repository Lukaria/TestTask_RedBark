#include "stdafx.h"
#include "Ball.h"

void Ball::Collide()
{
	--health;
}

void Ball::BoundCollision() {
	if (pos.x < 0 || pos.x > 974 - this->collider.getSize().x) health = 0;
	if (pos.y < 60 || pos.y > 768 - this->collider.getSize().y) health = 0;
}

void Ball::Draw()
{
	/*Render::device.SetTexturing(false);
	Render::DrawRect(collider.getLb().x, collider.getLb().y, collider.getRt().x - collider.getLb().x,
		collider.getRt().y - collider.getLb().y);
	Render::device.SetTexturing(true);*/

	this->texture->Bind();
	Render::DrawRect(this->pos.x, this->pos.y, texsize.x, texsize.y);	

	if (effect != nullptr) {
		effect->posX = pos.x + texsize.x / 2;
		effect->posY = pos.y + texsize.y / 2;
		effect->Reset();
	}
}


int Ball::Update(float dt)
{
	if (health <= 0 || lifetime <= 0) return id;
	else lifetime -= dt;

	pos.x += velocity.x * dt;
	pos.y += velocity.y * dt;
	setPos(Vector2{ pos.x, pos.y });
	if (isColliderExist()) {
		collider.UpdateCollider(this->pos);//коллайдер снаряда не надо сдвигать, он должен быть немного больше текстуры
	};
	return -1;
}
