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
