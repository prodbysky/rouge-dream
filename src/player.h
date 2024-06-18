#pragma once

#include <raylib.h>
#include <raymath.h>

class Player {
public:
    Player();

public:
    void Update(const Camera2D& camera);

    void Draw() const;

    const Vector2& GetPos() const;
    const Vector2& GetSize() const;

    Vector2 GetCenter() const;

    // Thanks ChatGPT :D
    float CenterMouseAngle(const Camera2D& camera) const;

private:
    static constexpr float m_speed = 500.0f;
    Vector2 m_pos;
    Vector2 m_size;
};
