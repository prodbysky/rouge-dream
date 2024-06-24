#pragma once

#include "bullet.h"
#include "weapon.h"

#include <memory>
#include <raylib.h>
#include <raymath.h>
#include <vector>

class Player {
public:
    Player(std::shared_ptr<Camera2D> camera);

public:
    void Update();

    void Draw() const;

    Rectangle GetRect() const;
    Vector2 GetPos() const;
    Vector2 GetSize() const;
    Vector2 GetCenter() const;

    void SetWeapon(Weapon w);

private:
    void Movement();
    static constexpr float m_speed = 1000.0f;
    Rectangle m_rect;
    Weapon m_weapon;
    std::shared_ptr<Camera2D> m_camera;
};
