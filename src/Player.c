#include "Player.h"
#include "GLOBAL.h"
#include "raylib.h"
#include "raymath.h"

#define P_BASE_SPEED 3.0f

t_player newPlayer() {
  t_player player;
  player.camera.position = (Vector3){0.0f, 2.0f, 0.0f};
  player.camera.fovy = 60.0f;
  player.camera.up = (Vector3){0.0f, 1.0f, 0.0f};
  player.camera.target = (Vector3){0.0f, 0.0f, 0.0f};
  player.camera.projection = CAMERA_PERSPECTIVE;
  player.yaw = 0.0f;
  player.pitch = 0.0f;
  player.direction = (Vector3){0.0f, 0.0f, 0.0f};
  player.speed = P_BASE_SPEED;
  DisableCursor();
  return player;
}

void PlayerUpdate(t_player *player) {
  MovePlayer(player);
  RotatePlayerView(player);
}

void MovePlayer(t_player *player) {
  if (IsKeyDown(KEY_W)) {
    player->camera.position.x +=
        player->direction.x * player->speed * GetFrameTime();
    player->camera.position.z +=
        player->direction.z * player->speed * GetFrameTime();
  }
  if (IsKeyDown(KEY_S)) {
    player->camera.position.x -=
        player->direction.x * player->speed * GetFrameTime();
    player->camera.position.z -=
        player->direction.z * player->speed * GetFrameTime();
  }
  if (IsKeyDown(KEY_D)) {
    player->camera.position.x +=
        -player->direction.z * player->speed * GetFrameTime();
    player->camera.position.z +=
        player->direction.x * player->speed * GetFrameTime();
  }
  if (IsKeyDown(KEY_A)) {
    player->camera.position.x +=
        player->direction.z * player->speed * GetFrameTime();
    player->camera.position.z +=
        -player->direction.x * player->speed * GetFrameTime();
  }
}

void RotatePlayerView(t_player *player) {
  Vector2 mouseMotion = GetMouseDelta();
  player->yaw += mouseMotion.x * 0.2f * GetFrameTime();
  player->pitch -= mouseMotion.y * 0.2f * GetFrameTime();
  //     Normalize Angles after the update
  player->yaw = NormalizeAngle(player->yaw);
  player->pitch = Clamp(player->pitch, -PI / 4.0f, PI / 4.0f);

  player->direction.x = cos(player->yaw) * cos(player->pitch);
  player->direction.y = sin(player->pitch);
  player->direction.z = sin(player->yaw) * cos(player->pitch);
  player->direction = Vector3Normalize(player->direction);
  player->camera.target =
      Vector3Add(player->camera.position, player->direction);
}

void DrawPlayerStats(t_player *player) {
  DrawRectangle(600, 5, 195, 100, Fade(SKYBLUE, 0.5f));
  DrawRectangleLines(600, 5, 195, 100, BLUE);
  DrawText("CAMERA STATUS: ", 610, 15, 10, BLACK);
  DrawText(TextFormat("- Yaw: %0.2f", player->yaw * RAD2DEG), 610, 40, 10,
           BLACK);
  DrawText(TextFormat("- Pitch: %0.2f", player->pitch * RAD2DEG), 610, 50, 10,
           BLACK);

  DrawText(TextFormat("- Position: (%06.3f, %06.3f, %06.3f)",
                      player->camera.position.x, player->camera.position.y,
                      player->camera.position.z),
           610, 60, 10, BLACK);
  DrawText(TextFormat("- Direction: (%06.3f, %06.3f, %06.3f)",
                      player->direction.x, player->direction.y,
                      player->direction.z),
           610, 75, 10, BLACK);
  DrawText(TextFormat("- Target: (%06.3f, %06.3f, %06.3f)",
                      player->camera.target.x, player->camera.target.y,
                      player->camera.target.z),
           610, 85, 10, BLACK);
}
