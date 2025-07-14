#include "GLOBAL.h"
#include "Player.h"
#include "raylib.h"

void Init(void);
void MainLoop(void);
void Draw(void);
void Update(void);
void End(void);

const int screenWidth = 960;
const int screenHeight = 640;

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
  DrawGrid(100, CELLSIZE);
  EndMode3D();

  DrawPlayerStats(&player);
  EndDrawing();
}

void Update(void) { PlayerUpdate(&player); }

void End(void) { CloseWindow(); }
