#pragma once

#include <memory>
#include <raylib.h>

class Bullet {
public:
    Bullet(Vector2 player_center, Vector2 size, Vector2 rotation, float speed,
           float ttl, std::shared_ptr<Camera2D> camera);
    void Update();
    void Draw() const;

public:
    float ttl;

private:
    Vector2 m_pos, m_size, m_rotation;
    float m_speed, m_angle;
    std::shared_ptr<Camera2D> m_camera;
};
