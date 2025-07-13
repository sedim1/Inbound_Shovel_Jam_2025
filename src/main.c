#include "Map.h"
#include "Player.h"
#include "raylib.h"

void Init(void);
void MainLoop(void);
void Draw(void);
void Update(void);
void End(void);

const int screenWidth = 800;
const int screenHeight = 640;

t_section section = {
    {1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 1},
};

t_player player;

int main(void) {
  Init();
  MainLoop();
  End();
  return 0;
}

void Init(void) {
  InitWindow(screenWidth, screenHeight, "INBOUND_SHOVEL JAM 2025");
  SetTargetFPS(60);
  player = newPlayer();
}

void MainLoop(void) {
  while (!WindowShouldClose()) {
    Update();
    Draw();
  }
}

void Draw(void) {
  BeginDrawing();
  ClearBackground(RAYWHITE);
  BeginMode3D(player.camera);
  DrawGrid(10, 1.0f);
  EndMode3D();
  EndDrawing();
}

void Update(void) { PlayerUpdate(&player); }

void End(void) { CloseWindow(); }
