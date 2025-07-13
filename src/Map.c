#include "Map.h"
#include "GLOBAL.h"
#include <raylib.h>

void DrawSectionWalls(t_section section) {
  for (unsigned int z = 0; z < SECTION_HEIGHT; z++) {
    for (unsigned int x = 0; x < SECTION_WITH; x++) {
      Vector3 position =
          (Vector3){x * CELLSIZE + CELLSIZE / 2.0f, CELLSIZE / 2.0f,
                    z * CELLSIZE + CELLSIZE / 2.0f};
      if (section[z][x] > 0) {
        DrawCube(position, CELLSIZE, CELLSIZE, CELLSIZE, RED);
        DrawCubeWires(position, CELLSIZE, CELLSIZE, CELLSIZE, BLACK);
      }
    }
  }
}
