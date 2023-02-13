#pragma once

struct Vector2 {
	float x, y;
};
Vector2 operator-(Vector2 v1, Vector2 v2);

Vector2 operator+(Vector2 v1, Vector2 v2);

Vector2 operator+(Vector2 v1, float d);

float DotProduct(Vector2 v1, Vector2 v2);

Vector2 operator*(Vector2 v1, float d);

inline float getLength(Vector2 vect) {
	return sqrt(vect.x * vect.x + vect.y * vect.y);
}
inline Vector2 getNormalizedV2(Vector2 vect) {
	float length = getLength(vect);
	return Vector2{ vect.x / length, vect.y / length };
}