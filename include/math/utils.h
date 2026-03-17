#ifndef DUST_MATH_UTILS_H
#define DUST_MATH_UTILS_H

#define DUST_PI     3.14159265f
#define DEG2RAD(d)  ((d) * DUST_PI / 180.0f)
#define RAD2DEG(r) ((r) * 180.0f / DUST_PI)

#define LERP(a, b, t) ((a) + ((b) - (a)) * (t))
#define CLAMP(x, lo, hi) ((x) < (lo) ? (lo) : (x) > (hi) ? (hi) : (x))
#define MIN(a, b)     ((a) < (b) ? (a) : (b))
#define MAX(a, b)     ((a) > (b) ? (a) : (b))
#define ABS(x) ((x) < 0 ? -(x) : (x))

#endif
