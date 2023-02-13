#pragma once
#include "GameObject.h"
class Ball :
    public GameObject
{
private:
    float lifetime = 15;
public:
    Ball(int id) :GameObject(Core::resourceManager.Get<Render::Texture>("cannonball"),
        Vector2{ 0, 0 }, Vector2{ 0, 0 }, 1, id) {
        this->damage = 1;
    };

    Ball(Vector2 mouse_pos) :GameObject(Core::resourceManager.Get<Render::Texture>("cannonball"),
        Vector2{ 30, 30 }, Vector2{ math::clamp(465.f, 568.f,mouse_pos.x - 20.f), 120}, 1)
    {
        this->damage = 1;
        this->velocity = getNormalizedV2(
            Vector2{
                mouse_pos.x - pos.x, 
                (mouse_pos.y - pos.y < 60 ? -(mouse_pos.y - pos.y) : mouse_pos.y - pos.y)})
                * 360;
    };
    void BoundCollision();

    void Collide() override;

    void Draw() override;

    int Update(float dt) override;
};

