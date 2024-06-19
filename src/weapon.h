#pragma once

#include "bullet.h"

#include <vector>

class Weapon {
public:
    Weapon(BulletConfig config, float reload_time,
           std::shared_ptr<Camera2D> camera);
    void Update();
    void Draw() const;
    void Shoot(float angle, Vector2 pos);

private:
    std::vector<Bullet> m_bullets;
    std::shared_ptr<Camera2D> m_camera;
    float m_reload_time;
    float m_reload_timer = 0;
    BulletConfig m_config;
};
