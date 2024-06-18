#pragma once

#include <raylib.h>

class Bullet {
public:
    Bullet(Vector2 player_center, Vector2 size, Vector2 rotation, float speed,
           float ttl, const Camera2D& camera);
    void Update(const Camera2D& camera);
    void Draw(const Camera2D& camera) const;

public:
    float ttl;

private:
    Vector2 m_pos, m_size, m_rotation;
    float m_speed, m_angle;
};
