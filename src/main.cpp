#include "player.h"

#include <cmath>
#include <memory>
#include <raylib.h>
#include <raymath.h>

constexpr Vector2 screen_size = {.x = 800, .y = 800};

class Pickup {
public:
    Pickup(Rectangle rect) : m_rect(rect) {}
    virtual void OnPickup(Player& player) const = 0;
    virtual void Draw() const { DrawRectangleRec(m_rect, RED); }
    const Rectangle& GetRect() const { return m_rect; }

private:
    Rectangle m_rect;
};

class WeaponPickup : public Pickup {
public:
    WeaponPickup(Rectangle rect, Weapon weapon) :
        Pickup(rect), m_weapon(weapon) {}
    virtual void OnPickup(Player& player) const override {
        player.SetWeapon(m_weapon);
    }

private:
    Weapon m_weapon;
};

int main() {
    InitWindow(screen_size.x, screen_size.y, "Rouge-dream");
    std::shared_ptr<Camera2D> camera = std::make_shared<Camera2D>(Camera2D{0});
    camera->zoom                     = 0.50f;
    camera->offset                   = {.x = 350, .y = 350};
    Player player(camera);

    WeaponPickup pickup(
        {
            200, 200, 100, 100
    },
        Weapon({400, 2, {50, 25}}, 0.25, camera));

    SetTargetFPS(120);

    while (!WindowShouldClose()) {
        if (CheckCollisionRecs(pickup.GetRect(), player.GetRect())) {
            pickup.OnPickup(player);
        }
        player.Update();
        camera->target = player.GetPos();
        BeginDrawing();
        ClearBackground(GetColor(0x181818ff));
        DrawFPS(10, 10);
        BeginMode2D(*camera);
        player.Draw();
        pickup.Draw();
        DrawRectangleV({400, 400}, {100, 100}, GREEN);
        EndMode2D();
        EndDrawing();
    }
}
