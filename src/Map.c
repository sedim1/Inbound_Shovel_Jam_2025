#include "Map.h"
#include "GLOBAL.h"
#include <raylib.h>
#include <stdio.h>

t_dungeon GenerateDungeon(int n_rooms) {
  t_dungeon dungeon;
  // Set all values of minimap to -1
  for (int y = 0; y < MAP_Y; y++)
    for (int x = 0; x < MAP_X; x++)
      dungeon.layout[y][x] = -1;
  // Create the layout of the map
  GenerateDungeonLayout(&dungeon, 0, n_rooms, -1, -1, -1);
  // Print dungeon layout on console
  for (int y = 0; y < MAP_Y; y++) {
    for (int x = 0; x < MAP_X; x++) {
      if (dungeon.layout[y][x] > 0)
        printf("1 ");
      else
        printf("0 ");
    }
    printf("\n");
  }
  return dungeon;
}

void GenerateDungeonLayout(t_dungeon *dungeon, int current_room, int n_rooms,
                           int room_x, int room_y, int came_from) {
  // Base case - n_rooms for had been created
  if (current_room >= n_rooms)
    return;
  // Dungeon currently has no rooms created
  if (room_x == -1 && room_y == -1) {
    int x = GetRandomValue(3, 6);
    int y = GetRandomValue(2, 4);
    // Recursive call to start from the first room
    GenerateDungeonLayout(dungeon, current_room, n_rooms, x, y, -1);
    return;
  } else { // Work on current room room
    // printf("Setting room in %d  %d\n", room_x, room_y);
    dungeon->layout[room_y][room_x] = 1;
    // Set assign a pattern for the current room layout
    // dungeon->dungeon_rooms[room_y][room_x].layout = pattern;
    // Define Room type
    dungeon->dungeon_rooms[room_y][room_x].type = EMPTY_ROOM;
    dungeon->dungeon_rooms[room_y][room_x].state = UNLOCKED;
    // Set unstarted neighbors on current room
    for (int n = 0; n < 4; n++)
      dungeon->dungeon_rooms[room_y][room_x].neighbors[n] = 0;

    //
    switch (came_from) {
    case NORTH:
      // printf("Came from North\n");
      dungeon->dungeon_rooms[room_y][room_x].neighbors[SOUTH] = 1;
      break;
    case SOUTH:
      // printf("Came from South\n");
      dungeon->dungeon_rooms[room_y][room_x].neighbors[NORTH] = 1;
      break;
    case EAST:
      // printf("Came from East\n");
      dungeon->dungeon_rooms[room_y][room_x].neighbors[WEST] = 1;
      break;
    case WEST:
      // printf("Came from West\n");
      dungeon->dungeon_rooms[room_y][room_x].neighbors[EAST] = 1;
      break;
    default:
      // printf("This is the first room\n");
      break;
    }

    // Define how many neighbors the current room will have
    int n_neighbors = GetRandomValue(1, 3);
    int attempts = 0;
    int next_neighbor = -1, next_y = -1, next_x = -1;
    int valid_position = 0;
    for (int neighbor = 0; neighbor < n_neighbors; neighbor++) {
      valid_position = 0;
      while (!valid_position && attempts < 8) {
        // printf("%d\n", valid_position);
        next_neighbor = GetRandomValue(0, 3);
        switch (next_neighbor) {
        case NORTH:
          next_x = room_x;
          next_y = room_y - 1;
          break;
        case SOUTH:
          next_x = room_x;
          next_y = room_y + 1;
          break;
        case EAST:
          next_y = room_y;
          next_x = room_x + 1;
          break;
        case WEST:
          next_y = room_y;
          next_x = room_x - 1;
          break;
        default:
          break;
        }
        // Repeat if it is out of bounds
        if (next_x < 0 || next_y < 0 || next_x >= MAP_X || next_y >= MAP_Y) {
          // printf("Out of bounds\n");
          continue;
        }
        // Repeat if the room already exists or it tries tu use the direction it
        // came from
        if (dungeon->layout[next_y][next_x] != -1 ||
            next_neighbor == came_from) {
          // printf("Room %d %d already exists\n", next_x, next_y);
          attempts++;
          continue;
        }

        // printf("valid position in %d %d\n", next_x, next_y);
        valid_position = 1;
      }
      // Recursive call if it is a valid position
      if (valid_position) {
        GenerateDungeonLayout(dungeon, current_room + 1, n_rooms, next_x,
                              next_y, next_neighbor);
      }
    }
    return;
  }
}
