#include "bullet.h"

#include "utils.h"

#include <raymath.h>

Bullet::Bullet(Vector2 player_center, Vector2 size, Vector2 rotation,
               float speed, float ttl, const Camera2D& camera) :
    m_size(size), m_rotation(rotation), m_speed(speed), ttl(ttl) {
    m_pos   = Vector2Add(player_center,
                         Vector2Scale(rotation, speed * GetFrameTime()));
    m_angle = CenterMouseAngle(m_pos, camera);
}

void Bullet::Update(const Camera2D& camera) {
    m_pos =
        Vector2Add(m_pos, Vector2Scale(m_rotation, m_speed * GetFrameTime()));
    ttl -= GetFrameTime();
}

void Bullet::Draw(const Camera2D& camera) const {
    DrawRectanglePro(
        {.x = m_pos.x, .y = m_pos.y, .width = m_size.x, .height = m_size.y},
        {m_size.x / 2, m_size.y / 2}, m_angle + 45, RED);
}
