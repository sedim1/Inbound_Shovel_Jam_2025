#include "GLOBAL.h"
#include <raylib.h>

float NormalizeAngle(float deg) {
  if (deg >= 2.0 * PI)
    return deg - (2.0f * PI);
  else if (deg < 0.0f)
    return deg + (2.0f * PI);
  else
    return deg;
}
