#pragma once

#include <raylib.h>

float CenterMouseAngle(const Vector2& point, const Camera2D& camera);
Vector2 Vector2MoveToAngle(const Vector2& origin, const float& angle,
                           const Vector2& speed);
