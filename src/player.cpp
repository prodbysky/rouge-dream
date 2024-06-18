#include "player.h"

Player::Player() : m_pos({.x = 350, .y = 350}), m_size({.x = 100, .y = 100}) {}

void Player::Update(const Camera2D& camera) {
    float speed = this->m_speed * GetFrameTime();
    float angle = CenterMouseAngle(camera) - 45;

    bool key_down = IsKeyDown(KEY_A) || IsKeyDown(KEY_D) || IsKeyDown(KEY_W) ||
                    IsKeyDown(KEY_S);

    if (IsKeyDown(KEY_A)) {
        angle -= 90;
    }

    if (IsKeyDown(KEY_D)) {
        angle += 90;
    }

    if (IsKeyDown(KEY_S)) {
        angle += 180;
    }

    Vector2 rotation_angle =
        Vector2Normalize(Vector2Rotate({1, 1}, DEG2RAD * angle));
    if (key_down) {
        m_pos.x += rotation_angle.x * speed;
        m_pos.y += rotation_angle.y * speed;
    }
}

void Player::Draw() const { DrawCircleV(GetCenter(), 100, RED); }

const Vector2& Player::GetPos() const { return m_pos; }
const Vector2& Player::GetSize() const { return m_size; }

Vector2 Player::GetCenter() const {
    return Vector2Add(m_pos, Vector2Divide(m_size, {2, 2}));
}

// Thanks ChatGPT :D
float Player::CenterMouseAngle(const Camera2D& camera) const {
    Vector2 dir = Vector2Subtract(
        GetScreenToWorld2D(GetMousePosition(), camera), GetCenter());

    float angle = atan2f(dir.y, dir.x) * RAD2DEG;

    if (angle < 0)
        angle += 360;
    return angle;
}
