#include "utils.h"

#include <cmath>
#include <raymath.h>

float CenterMouseAngle(const Vector2& point, const Camera2D& camera) {
    Vector2 dir =
        Vector2Subtract(GetScreenToWorld2D(GetMousePosition(), camera), point);

    float angle = atan2f(dir.y, dir.x) * RAD2DEG;

    if (angle < 0)
        angle += 360;
    return angle - 45;
}

// NOTE: Angle is in degress
Vector2 Vector2MoveToAngle(const Vector2& origin, const float& angle,
                           const Vector2& speed) {
    Vector2 rotation_angle =
        Vector2Normalize(Vector2Rotate({1, 1}, DEG2RAD * angle));

    return Vector2Add(origin, Vector2Multiply(speed, rotation_angle));
}
