#include "weapon.h"

Weapon::Weapon(BulletConfig config, std::shared_ptr<Camera2D> camera) :
    m_config(config), m_camera(camera) {}

void Weapon::Shoot(float angle, Vector2 pos) {
    m_bullets.push_back(Bullet(pos, angle, m_config, m_camera));
}

void Weapon::Update() {
    for (size_t i = 0; i < m_bullets.size(); i++) {
        auto& bullet = m_bullets[i];
        if (bullet.ttl <= 0) {
            m_bullets.erase(m_bullets.begin() + i);
        }

        bullet.Update();
    }
}

void Weapon::Draw() const {
    for (const auto& bullet : m_bullets) {
        bullet.Draw();
    }
}
