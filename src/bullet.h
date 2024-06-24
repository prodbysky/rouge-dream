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
    Vector2 GetPos() const;
    Vector2 GetSize() const;

public:
    float ttl;

private:
    Rectangle m_rect;
    float m_angle, m_speed;
    std::shared_ptr<Camera2D> m_camera;
};
