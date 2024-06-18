#include <raylib.h>

constexpr Vector2 screen_size = {.x = 800, .y = 800};

class Player {
public:
    Player() : pos({.x = 350, .y = 350}), size({.x = 100, .y = 100}) {}

public:
    void Update() {
        float speed = this->speed * GetFrameTime();
        if (IsKeyDown(KEY_A)) {
            pos.x -= speed;
        }

        if (IsKeyDown(KEY_D)) {
            pos.x += speed;
        }

        if (IsKeyDown(KEY_W)) {
            pos.y -= speed;
        }

        if (IsKeyDown(KEY_S)) {
            pos.y += speed;
        }
    }
    void Draw() const { DrawRectangleV(pos, size, RED); }

    const Vector2& GetPos() const { return pos; }
    const Vector2& GetSize() const { return size; }

private:
    static constexpr float speed = 500.0f;
    Vector2 pos;
    Vector2 size;
};

int main() {
    InitWindow(screen_size.x, screen_size.y, "Rouge-dream");
    Player player;
    Camera2D camera = {0};
    camera.zoom     = 1.0f;
    camera.offset   = {.x = 350, .y = 350};

    SetTargetFPS(120);

    while (!WindowShouldClose()) {
        player.Update();
        camera.target = player.GetPos();
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawFPS(10, 10);
        BeginMode2D(camera);
        DrawRectangleV({250, 250}, {100, 100}, BLUE);
        player.Draw();
        EndMode2D();
        EndDrawing();
    }
}
