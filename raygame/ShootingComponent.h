#pragma once
#include "Component.h"
class ShootingComponent :
    public Component {
public:
    ShootingComponent();
    ~ShootingComponent();

    void start() override;
    void update(float deltaTime) override;

private:
};

