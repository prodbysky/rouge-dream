#pragma once

#include "bullet.h"

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

    const Vector2& GetPos() const;
    const Vector2& GetSize() const;

    Vector2 GetCenter() const;

private:
    void Movement();
    void Fire();
    static constexpr float m_speed = 1000.0f;
    Vector2 m_pos;
    Vector2 m_size;
    std::vector<Bullet> bullets;
    std::shared_ptr<Camera2D> m_camera;
};
