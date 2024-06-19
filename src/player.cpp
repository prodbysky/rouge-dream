#include "player.h"

#include "utils.h"

#include <memory>
#include <raylib.h>
#include <raymath.h>

Player::Player(std::shared_ptr<Camera2D> camera) :
    m_pos({
        .x = 350, .y = 350
}),
    m_size({.x = 100, .y = 100}), m_camera(camera),
    m_weapon({-1, -1, {0, 0}}, nullptr) {
    m_weapon = Weapon(
        {
            1000, 2, {100, 50}
    },
        m_camera);
}

void Player::Update() {
    Movement();
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
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
        m_pos = Vector2MoveToAngle(m_pos, angle, {speed, speed});
    }
}

void Player::Draw() const {
    DrawCircleV(GetCenter(), 100, RED);
    m_weapon.Draw();
}

const Vector2& Player::GetPos() const { return m_pos; }
const Vector2& Player::GetSize() const { return m_size; }

Vector2 Player::GetCenter() const {
    return Vector2Add(m_pos, Vector2Divide(m_size, {2, 2}));
}
