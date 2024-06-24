#include "player.h"

#include "utils.h"

#include <memory>
#include <raylib.h>
#include <raymath.h>

Player::Player(std::shared_ptr<Camera2D> camera) :
    m_rect({
        .x = 350, .y = 350, .width = 100, .height = 100
}),
    m_camera(camera), m_weapon({-1, -1, {0, 0}}, 0, nullptr) {
    m_weapon = Weapon(
        {
            1000, 2, {100, 50}
    },
        0.25, m_camera);
}

void Player::Update() {
    Movement();
    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
        m_weapon.Shoot(CenterMouseAngle(GetCenter(), *m_camera), GetCenter());
    }
    m_weapon.Update();
}

void Player::Movement() {
    float speed = this->m_speed * GetFrameTime();
    float angle = CenterMouseAngle(GetCenter(), *m_camera);

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

    if (key_down) {
        Vector2 new_pos = Vector2MoveToAngle({.x = m_rect.x, .y = m_rect.y},
                                             angle, {speed, speed});
        m_rect.x        = new_pos.x;
        m_rect.y        = new_pos.y;
    }
}

void Player::Draw() const {
    DrawCircleV(GetCenter(), 100, RED);
    m_weapon.Draw();
}

Vector2 Player::GetPos() const { return {m_rect.x, m_rect.y}; }
Vector2 Player::GetSize() const { return {m_rect.width, m_rect.height}; }
Vector2 Player::GetCenter() const {
    return Vector2Add(GetPos(), Vector2Divide(GetSize(), {2, 2}));
}
Rectangle Player::GetRect() const { return m_rect; }

void Player::SetWeapon(Weapon w) { m_weapon = w; }
