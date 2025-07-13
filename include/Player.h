#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>

typedef struct {
  Camera3D camera;
  Vector3 direction;
  float yaw;
  float pitch;
} t_player;

t_player newPlayer();
void PlayerUpdate(t_player *player);
void MovePlayer(t_player *player);
void RotatePlayerView(t_player *player);

void DrawPlayerStats(t_player *player);
#endif
