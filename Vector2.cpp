
#include "stdafx.h"
#include "Vector2.h"


Vector2 operator-(Vector2 v1, Vector2 v2) {
	Vector2 result;
	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	return result;
}

Vector2 operator+(Vector2 v1, Vector2 v2) {
	Vector2 result;
	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	return result;
}

Vector2 operator+(Vector2 v1, float d)
{
	return Vector2{ v1.x + d, v1.y + d };
}

float DotProduct(Vector2 v1, Vector2 v2) {
	return v1.x * v2.x + v1.y * v2.y;
}

Vector2 operator*(Vector2 v1, float d) {
	v1.x *= d;
	v1.y *= d;
	return v1;
}
