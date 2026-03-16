#ifndef DUST_MATH_H
#define DUST_MATH_H

#define VEC2(x, y) ((Vec2){(x), (y)})
#define VEC2_ZERO ((Vec2){0.0f, 0.0f})
#define VEC2_ONE ((Vec2){1.0f, 1.0f})

typedef struct {
  float x, y;
} Vec2;

// unary operations
Vec2 vec2_neg(Vec2 a);

// binary operations
Vec2 vec2_add(Vec2 a, Vec2 b);
Vec2 vec2_sub(Vec2 a, Vec2 b);

#endif
