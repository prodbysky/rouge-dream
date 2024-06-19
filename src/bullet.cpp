#include "bullet.h"

#include "raylib.h"
#include "utils.h"

#include <memory>
#include <raymath.h>

Bullet::Bullet(Vector2 player_center, float angle, BulletConfig config,
               std::shared_ptr<Camera2D> camera) :
    m_size(config.size), m_speed(config.speed), ttl(config.ttl) {
    m_camera         = camera;
    Vector2 rotation = Vector2Rotate({1, 1}, angle);
    m_pos            = Vector2Add(player_center,
                                  Vector2Scale(rotation, m_speed * GetFrameTime()));
    m_angle          = CenterMouseAngle(m_pos, *m_camera);
}

void Bullet::Update() {
    float speed  = m_speed * GetFrameTime();
    m_pos        = Vector2MoveToAngle(m_pos, m_angle, {speed, speed});
    ttl         -= GetFrameTime();
}

void Bullet::Draw() const {
    DrawRectanglePro(
        {.x = m_pos.x, .y = m_pos.y, .width = m_size.x, .height = m_size.y},
        {m_size.x / 2, m_size.y / 2}, m_angle + 45, RED);
}
