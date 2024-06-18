#pragma once

#include "bullet.h"

#include <raylib.h>
#include <raymath.h>
#include <vector>

class Player {
public:
    Player();

public:
    void Update(const Camera2D& camera);

    void Draw(const Camera2D& camera) const;

    const Vector2& GetPos() const;
    const Vector2& GetSize() const;

    Vector2 GetCenter() const;

private:
    void Movement(const Camera2D& camera);
    void Fire(const Camera2D& camera);
    static constexpr float m_speed = 500.0f;
    Vector2 m_pos;
    Vector2 m_size;
    std::vector<Bullet> bullets;
};
