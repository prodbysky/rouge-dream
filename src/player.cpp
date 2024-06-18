#include "player.h"

#include "utils.h"

#include <raylib.h>
#include <raymath.h>

Player::Player() : m_pos({.x = 350, .y = 350}), m_size({.x = 100, .y = 100}) {}

void Player::Update(const Camera2D& camera) {
    Movement(camera);

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Fire(camera);
    }

    for (size_t i = 0; i < bullets.size(); i++) {
        if (bullets[i].ttl <= 0) {
            bullets.erase(bullets.begin() + i);
        }

        bullets[i].Update(camera);
    }
}

void Player::Fire(const Camera2D& camera) {
    Vector2 rotation = Vector2Normalize(
        Vector2Rotate({1, 1}, DEG2RAD * CenterMouseAngle(GetCenter(), camera)));
    bullets.push_back(
        Bullet(GetCenter(), {100, 50}, rotation, 2000, 0.5, camera));
}

void Player::Movement(const Camera2D& camera) {
    float speed = this->m_speed * GetFrameTime();
    float angle = CenterMouseAngle(GetCenter(), camera);

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
        m_pos = Vector2Add(m_pos, Vector2Scale(rotation_angle, speed));
    }
}

void Player::Draw(const Camera2D& camera) const {
    DrawCircleV(GetCenter(), 100, RED);
    for (const auto& bullet : bullets) {
        bullet.Draw(camera);
    }
}

const Vector2& Player::GetPos() const { return m_pos; }
const Vector2& Player::GetSize() const { return m_size; }

Vector2 Player::GetCenter() const {
    return Vector2Add(m_pos, Vector2Divide(m_size, {2, 2}));
}
