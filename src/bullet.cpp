#include "bullet.h"

#include "raylib.h"
#include "utils.h"

#include <memory>
#include <raymath.h>

Bullet::Bullet(Vector2 player_center, float angle, BulletConfig config,
               std::shared_ptr<Camera2D> camera) :
    m_rect({.x = -1, .y = -1, .width = config.size.x, .height = config.size.y}),
    m_speed(config.speed), ttl(config.ttl) {
    m_camera         = camera;
    Vector2 rotation = Vector2Rotate({1, 1}, angle);
    Vector2 pos      = Vector2Add(player_center,
                                  Vector2Scale(rotation, m_speed * GetFrameTime()));
    m_rect.x         = pos.x;
    m_rect.y         = pos.y;
    m_angle          = CenterMouseAngle(GetPos(), *m_camera);
    m_texture        = GetTexture();
}

void Bullet::Update() {
    float speed  = m_speed * GetFrameTime();
    Vector2 pos  = Vector2MoveToAngle(GetPos(), m_angle, {speed, speed});
    m_rect.x     = pos.x;
    m_rect.y     = pos.y;
    ttl         -= GetFrameTime();
}

void Bullet::Draw() const {
    DrawTexturePro(m_texture, {0, 0, m_rect.width, m_rect.height}, m_rect,
                   {m_rect.width / 2, m_rect.height / 2}, m_angle + 45, WHITE);
}

Texture2D Bullet::GetTexture() {
    if (m_texture.height == 0) {
        m_texture = LoadTexture("../assets/bullet.png");
    }

    return m_texture;
}

Vector2 Bullet::GetPos() const { return {m_rect.x, m_rect.y}; }
Vector2 Bullet::GetSize() const { return {m_rect.width, m_rect.height}; }
