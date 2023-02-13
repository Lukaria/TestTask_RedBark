#pragma once
#include "Collider.h"
#include "Vector2.h"

class GameObject
{
protected:
	int id;
	Render::Texture* texture;
	Collider collider;
	Vector2 velocity;
	Vector2 pos;
	unsigned health;
	Vector2 texsize;
	int damage = 0;
	ParticleEffectPtr effect;
	std::string texname;

public:
	
	GameObject() : collider(Vector2{ 0, 0 }), velocity(Vector2{0, 0}) {};

	GameObject(Render::Texture* texture, Vector2 texsize, Vector2 pos, unsigned health, unsigned id) :
		texture(texture), texsize(texsize), collider(texsize), pos(pos),  
		health(health), id(id), velocity(Vector2{ 0, 0 }) {};

	GameObject(Render::Texture* texture, Vector2 texsize, Vector2 pos, unsigned health) :
		texture(texture), texsize(texsize), collider(texsize), pos(pos),  
		health(health), velocity(Vector2{ 0, 0 }) {};


	void setTexsize(Vector2 texsize) { this->texsize = texsize; }
	Vector2 getTexsize() { return texsize; }

	Vector2 getVelocity() { return velocity; }

	void setVelocity(Vector2 velocity) { this->velocity = velocity; }

	void setTexture(Render::Texture* texture) { this->texture = texture; }

	Render::Texture* getTexture() { return texture; }

	void setCollider(Collider collider) { this->collider = collider; 
	(this->collider).UpdateCollider(this->pos); 
	}

	Collider getCollider() { return collider; }	

	void setEffect(ParticleEffectPtr effect) { this->effect = effect; }

	int getId() { return id; }

	void setId(unsigned id) { this->id = id; }

	bool isColliderExist() { return collider.getRt().x && collider.getRt().y; }

	Vector2 getPos() { return pos; }

	void setPos(Vector2 pos) { 
		this->pos = pos; 
		if (isColliderExist()) {
			collider.UpdateCollider(this->pos);
		}
	}
	int getDamage() { return damage; }
	void setDamage(int damage) { this->damage = damage; }
	virtual int Update(float dt) = 0;

	virtual void Draw() = 0;

	virtual void Collide() = 0;

	void setTexture(std::string texture) {
		this->texname = texture;
		this->texture = Core::resourceManager.Get<Render::Texture>(texture);
	}

	void BoundCollision();
	int getHealth() { return health; }

	void setHealth(int health) { this->health = health; }
};

