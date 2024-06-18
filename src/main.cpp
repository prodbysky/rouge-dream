#include <cmath>
#include <raylib.h>
#include <raymath.h>

constexpr Vector2 screen_size = {.x = 800, .y = 800};

class Player {
public:
    Player() : m_pos({.x = 350, .y = 350}), m_size({.x = 100, .y = 100}) {}

public:
    void Update(const Camera2D& camera) {
        float speed = this->m_speed * GetFrameTime();
        float angle = CenterMouseAngle(camera) - 45;

        bool key_down = IsKeyDown(KEY_A) || IsKeyDown(KEY_D) ||
                        IsKeyDown(KEY_W) || IsKeyDown(KEY_S);

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

    void Draw() const { DrawCircleV(GetCenter(), 100, RED); }

    const Vector2& GetPos() const { return m_pos; }
    const Vector2& GetSize() const { return m_size; }

    Vector2 GetCenter() const {
        return Vector2Add(m_pos, Vector2Divide(m_size, {2, 2}));
    }

    // Thanks ChatGPT :D
    float CenterMouseAngle(const Camera2D& camera) const {
        Vector2 dir = Vector2Subtract(
            GetScreenToWorld2D(GetMousePosition(), camera), GetCenter());

        float angle = atan2f(dir.y, dir.x) * RAD2DEG;

        if (angle < 0)
            angle += 360;
        return angle;
    }

private:
    static constexpr float m_speed = 500.0f;
    Vector2 m_pos;
    Vector2 m_size;
};

int main() {
    InitWindow(screen_size.x, screen_size.y, "Rouge-dream");
    Player player;
    Camera2D camera = {0};
    camera.zoom     = 1.0f;
    camera.offset   = {.x = 350, .y = 350};

    SetTargetFPS(120);

    while (!WindowShouldClose()) {
        player.Update(camera);
        camera.target = player.GetPos();
        BeginDrawing();
        ClearBackground(GetColor(0x181818ff));
        DrawFPS(10, 10);
        BeginMode2D(camera);
        player.Draw();
        DrawRectangleV({200, 200}, {100, 100}, BLUE);
        EndMode2D();
        EndDrawing();
    }
}
