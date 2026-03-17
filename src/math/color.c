#include "math/color.h"
#include "math/utils.h"

Color color_lerp(Color a, Color b, float t) {
  return (Color){.red = LERP(a.red, b.red, t),
                 .blue = LERP(a.blue, b.blue, t),
                 .green = LERP(a.green, b.green, t),
                 .alpha = LERP(a.alpha, b.alpha, t)};
}
