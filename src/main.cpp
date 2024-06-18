#include <raylib.h>

int main() {
    InitWindow(800, 800, "Rouge-dream");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }
}
