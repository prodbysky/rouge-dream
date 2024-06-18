#include "player.h"

#include <cmath>
#include <raylib.h>
#include <raymath.h>

constexpr Vector2 screen_size = {.x = 800, .y = 800};

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
        DrawRectangleV({200, 200}, {100, 100},
                       BLUE); // A reference point for movement
        EndMode2D();
        EndDrawing();
    }
}
