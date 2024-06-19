#pragma once

#include <memory>
#include <raylib.h>

struct BulletConfig {
    float speed;
    float ttl;
    Vector2 size;
};

class Bullet {
public:
    Bullet(Vector2 player_center, float angle, BulletConfig config,
           std::shared_ptr<Camera2D> camera);
    void Update();
    void Draw() const;

public:
    float ttl;

private:
    Vector2 m_pos, m_size;
    float m_angle, m_speed;
    std::shared_ptr<Camera2D> m_camera;
};
