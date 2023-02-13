#pragma once
#include "GameObject.h"
#include <Utils/FPoint.h>
class Target :
    public GameObject
{
public:
    Target() { health = 1; velocity = { 0, 0 }; }
    Target(Vector2 pos, unsigned health) :GameObject(Core::resourceManager.Get<Render::Texture>("target"), 
        Vector2{ 60, 60 }, pos, health) {
        this->damage = 0;
    };


    Target(std::string texture, Vector2 pos, unsigned health) :GameObject(
        Core::resourceManager.Get<Render::Texture>(texture),
        Vector2{ 60, 60 }, pos, health) {
        this->damage = 0;
    };

    void Collide() override;

    void Draw() override;
    
    int Update(float dt) override;

};

