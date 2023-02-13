
#include "stdafx.h"
#include "Collider.h"

void Collider::UpdateCollider(Vector2 pos) {
	this->lb = pos;
	this->rt = pos + this->size;
}