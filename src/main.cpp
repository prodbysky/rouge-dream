#include "player.h"

#include <cmath>
#include <memory>
#include <raylib.h>
#include <raymath.h>

constexpr Vector2 screen_size = {.x = 800, .y = 800};

int main() {
    InitWindow(screen_size.x, screen_size.y, "Rouge-dream");
    std::shared_ptr<Camera2D> camera = std::make_shared<Camera2D>(Camera2D{0});
    camera->zoom                     = 0.50f;
    camera->offset                   = {.x = 350, .y = 350};
    Player player(camera);

    SetTargetFPS(120);

    while (!WindowShouldClose()) {
        player.Update();
        camera->target = player.GetPos();
        BeginDrawing();
        ClearBackground(GetColor(0x181818ff));
        DrawFPS(10, 10);
        BeginMode2D(*camera);
        player.Draw();
        DrawRectangleV({400, 400}, {100, 100}, GREEN);
        EndMode2D();
        EndDrawing();
    }
}
