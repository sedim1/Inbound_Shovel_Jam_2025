#ifndef MAP_H
#define MAP_H

#include "GLOBAL.h"
#include <raylib.h>

typedef int t_minimap[MAP_Y][MAP_X]; // General layout of dungeon
typedef int t_buffer[ROOM_HEIGHT]
                    [ROOM_WIDTH]; // General layout of a room in the dungeon

enum ROOM_TYPE {
  EMPTY_ROOM, // ROOM WITH NO ENEMIERS
  ENEMY_ROOM, // ROOM WITH ENEMIES
  BOOS_ROOM,  // ROOM WITH BOSS/BOSSES
};

enum ROOM_STATE {
  LOCKED,   // Room still has enemies
  UNLOCKED, // Room is empty or enemies or boss had been defeated
};

enum C_DIRECTIONS {
  NORTH = 0,
  SOUTH = 1,
  EAST = 2,
  WEST = 3,
};

typedef struct {
  enum ROOM_TYPE type;
  enum ROOM_STATE state;
  int neighbors[4]; // 0=North, 1=South, 2=East, 3=West;
  t_buffer layout;
} t_room;

typedef struct {
  t_minimap layout;
  t_room dungeon_rooms[MAP_Y][MAP_X];
} t_dungeon;

t_dungeon GenerateDungeon(int n_rooms);
void GenerateDungeonLayout(t_dungeon *dungeon, int current_room, int n_rooms,
                           int room_x, int room_y, int came_from);

void DrawDungeonRooms(t_dungeon *dungeon);

#endif
