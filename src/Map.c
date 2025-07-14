#include "Map.h"
#include "GLOBAL.h"
#include <raylib.h>

t_map CreateMap(t_section patterns[], int n_patterns) {
  t_map m;
  do {
    m.section_start[0] = GetRandomValue(0, MPMAX_SIZE - 1);
    m.section_end[0] = GetRandomValue(0, MPMAX_SIZE - 1);
    m.section_start[1] = GetRandomValue(0, MPMAX_SIZE - 1);
    m.section_end[1] = GetRandomValue(0, MPMAX_SIZE - 1);
  } while (m.section_start[0] == m.section_end[0] &&
           m.section_start[1] == m.section_end[1]);
  return m;
}
void GenerateLayout(t_map *map, t_section patterns[], int n_patterns) {}
