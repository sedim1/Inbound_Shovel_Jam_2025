#include "raylib.h"

void Init(void);
void MainLoop(void);
void Draw(void);
void Update(void);
void End(void);

const int screenWidth = 800;
const int screenHeight = 640;

int main(void) {
  Init();
  MainLoop();
  End();
  return 0;
}

void Init(void) {
  InitWindow(screenWidth, screenHeight, "INBOUND_SHOVEL JAM 2025");
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
  DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
  EndDrawing();
}

void Update(void) {}

void End(void) { CloseWindow(); }
