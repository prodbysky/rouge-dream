#include "bullet.h"

#include "raylib.h"
#include "utils.h"

#include <memory>
#include <raymath.h>

Bullet::Bullet(Vector2 player_center, Vector2 size, Vector2 rotation,
               float speed, float ttl, std::shared_ptr<Camera2D> camera) :
    m_size(size), m_rotation(rotation), m_speed(speed), ttl(ttl) {
    m_camera = camera;
    m_pos    = Vector2Add(player_center,
                          Vector2Scale(rotation, speed * GetFrameTime()));
    m_angle  = CenterMouseAngle(m_pos, *m_camera);
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
