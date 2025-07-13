#include "Map.h"
#include "GLOBAL.h"
#include <raylib.h>

void DrawSectionWalls(t_section *section) {
  for (unsigned int z = 0; z < SECTION_HEIGHT; z++) {
    for (unsigned int x = 0; x < SECTION_WITH; x++) {
      if (section[z][x] > 0) {
        Vector3 position = (Vector3){x * CELLSIZE, 0.0f, z * CELLSIZE};
        DrawCube(position, CELLSIZE, CELLSIZE, CELLSIZE, RED);
      }
    }
  }
}
