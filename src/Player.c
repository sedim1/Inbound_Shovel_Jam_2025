#include "Player.h"
#include "GLOBAL.h"
#include "raylib.h"
#include "raymath.h"
#include <stdio.h>

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
  DisableCursor();
  return player;
}

void PlayerUpdate(t_player *player) {
  RotatePlayerView(player);
  MovePlayer(player);
}

void MovePlayer(t_player *player) {}

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

void DrawPlayerStats(t_player *player) {}
