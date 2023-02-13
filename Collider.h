#pragma once

#include "Vector2.h"

class Collider
{
private:
	Vector2 size; //размер (совпадает с координатами)
	Vector2 lb; //нижний левый угол коллайдера
	Vector2 rt; //верхний правый
public:
	Collider() {
		lb = { 0, 0 };
		rt = { 0, 0 };
	}

	Collider(Vector2 size) {
		lb.x = 0;
		lb.y = 0;
		rt.x = size.x;
		rt.y = size.y;
		this->size = size;
	}

	Vector2 getLb() { return lb; }
	Vector2 getRt() { return rt; }
	Vector2 getSize() { return size; }

	void setSize(Vector2 size) { this->size = size; }

	void setLb(Vector2 lb) { this->lb = lb; }

	void setRt(Vector2 rt) { this->rt = rt; }

	void UpdateCollider(Vector2 pos);
};

