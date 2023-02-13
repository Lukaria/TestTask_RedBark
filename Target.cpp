#include "stdafx.h"
#include "Target.h"

void Target::Collide()
{
}

void Target::Draw()
{
	//отображение коллайдера
	//Render::device.SetTexturing(false);
	//Render::DrawRect(collider.getLb().x, collider.getLb().y, collider.getRt().x - collider.getLb().x,
	//	collider.getRt().y - collider.getLb().y);

	//Render::device.SetTexturing(true);
	this->texture->Bind();
	Render::DrawRect(pos.x, pos.y, texsize.x, texsize.y);

	if (effect != nullptr) {
	effect->posX = pos.x + texsize.x / 2;
	effect->posY = pos.y + texsize.y / 2;
	effect->Reset();
	}

}

int Target::Update(float dt)
{
	GameObject:BoundCollision();
	if (health <= 0) return id;

	pos.x += velocity.x * dt;
	pos.y += velocity.y * dt;

	setPos(Vector2{ pos.x, pos.y });
	if (isColliderExist()) {
		collider.UpdateCollider(this->pos + 5.0f);//сдвиг коллайдера для графического реализма
	};
	return -1;
}
