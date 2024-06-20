#include "weapon.h"

Weapon::Weapon(BulletConfig config, float reload_time,
               std::shared_ptr<Camera2D> camera) :
    m_config(config), m_camera(camera), m_reload_time(reload_time) {}

void Weapon::Shoot(float angle, Vector2 pos) {
    if (m_reload_timer <= 0) {
        m_bullets.emplace_back(Bullet(pos, angle, m_config, m_camera));
        m_reload_timer = m_reload_time;
    }
}

void Weapon::Update() {
    for (size_t i = 0; i < m_bullets.size(); i++) {
        auto& bullet = m_bullets[i];
        if (bullet.ttl <= 0) {
            m_bullets.erase(m_bullets.begin() + i);
        }

        bullet.Update();
    }
    m_reload_timer -= GetFrameTime();
}

void Weapon::Draw() const {
    for (const auto& bullet : m_bullets) {
        bullet.Draw();
    }
}
