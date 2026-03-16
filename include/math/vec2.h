#ifndef DUST_MATH_H
#define DUST_MATH_H

#define VEC2(x, y) ((Vec2){(x), (y)})
#define VEC2_ZERO ((Vec2){0.0f, 0.0f})
#define VEC2_ONE ((Vec2){1.0f, 1.0f})

typedef struct {
  float x, y;
} Vec2;

Vec2 vec2_negate(Vec2 vec);
Vec2 vec2_from_angle(float rad);
Vec2 vec2_normalize(Vec2 vec);
float vec2_magnitude(Vec2 vec);
float vec2_angle(Vec2 vec);

Vec2 vec2_add(Vec2 a, Vec2 b);
Vec2 vec2_sub(Vec2 a, Vec2 b);
Vec2 vec2_scale(Vec2 vec, float scalar);

// Projects b onto â. Assumed that a is normalized.
Vec2 vec2_vector_projection(Vec2 a, Vec2 b);

// Projects b onto â. Assumed that a is normalized.
float vec2_scalar_projection(Vec2 a, Vec2 b);

float vec2_dot(Vec2 a, Vec2 b);
float vec2_distance(Vec2 a, Vec2 b);

#endif
