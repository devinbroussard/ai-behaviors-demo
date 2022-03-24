#pragma once
#include "Actor.h"
class MoveComponent;

class Bullet :
    public Actor {
public:
    Bullet(Actor* owner);
    ~Bullet();

    //Shoots this bullet
    void shoot();
    void enable() {m_enabled = true; }
    //Returns whether or not this bullet is enabled
    bool isEnabled() { return m_enabled; }
    //Returns the move component
    MoveComponent* getMoveComponent() { return m_moveComponent; }
    //Resets this bullets' position to be its owner's position
    void resetPosition();

    //Adds necessary components to this bullet
    void start() override;
    //Handles disabling bullets
    void update(float deltaTime) override;
    //Draws the bullet to the scene
    void draw() override;
    //Handles on collision events
    void onCollision(Actor* actor) override;

private:
    //Whether or not this actor will be updated every frame
    bool m_enabled = false;
    Actor* m_owner = nullptr;
    MoveComponent* m_moveComponent = nullptr;
    float m_timer = 0;
};

