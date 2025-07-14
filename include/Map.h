#ifndef MAP_H
#define MAP_H

#include "GLOBAL.h"
#include <raylib.h>

typedef struct {
  int layout[SECTION_HEIGHT][SECTION_WIDTH];
  int yHeight;
} t_section;

typedef struct {
  int section_start[2];
  int section_end[2];
  t_section *map[MPMAX_SIZE][MPMAX_SIZE];
} t_map;

t_map CreateMap(t_section patterns[], int n_patterns);
void GenerateLayout(t_map *map, t_section patterns[], int n_patterns);

#endif
