#include "stdafx.h"
#include "Collision.h"


bool Collision::isCollide(Collider co1, Collider co2) const
{
	return (co2.getLb().x <= co1.getRt().x && co1.getLb().x <= co2.getRt().x) &&
		(co2.getLb().y <= co1.getRt().y && co1.getLb().y <= co2.getRt().y);
}

Vector2 Collision::getNormal(GameObject& go1, GameObject& go2) const
{
	Vector2 normal = { 0, 0 };
	if (go2.getCollider().getLb().x <= go1.getCollider().getRt().x &&
		go2.getCollider().getLb().x != go1.getCollider().getLb().x) normal.x = -1;

	if (go2.getCollider().getLb().y <= go1.getCollider().getRt().y &&
		go2.getCollider().getLb().y != go1.getCollider().getLb().y) normal.y = -1;

	return normal;
}


void Collision::ResolveCollision(GameObject& go1, GameObject& go2)
{
	//if (go1 == go2) return;

	if (!(go1.isColliderExist() && go2.isColliderExist())) return;
	Collider c1 = go1.getCollider(), c2 = go2.getCollider();
	if (!isCollide(c1, c2)) return;

	Vector2 normal = getNormal(go1, go2);
	Vector2 relativeV = go2.getVelocity() - go1.getVelocity();
	float van = DotProduct(relativeV, normal);

	float J = -van;
	Vector2 impulse = normal * J;
	go1.setHealth(go1.getHealth() - go2.getDamage());
	go2.setHealth(go2.getHealth() - go1.getDamage());

	go1.Collide();
	go2.Collide();


	if(go2.getHealth() != 0)
		go1.setVelocity(getNormalizedV2(go1.getVelocity() - impulse * 0.8) * getLength(go1.getVelocity()));
	if (go1.getHealth() != 0)
		go2.setVelocity(getNormalizedV2(go2.getVelocity() + impulse * 0.8) * -getLength(go2.getVelocity()));


}


