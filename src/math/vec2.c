#include "math/vec2.h"

Vec2 vec2_new(float x, float y) { return VEC2(x, y); }
Vec2 vec2_neg(Vec2 a) { return VEC2(a.x * -1, a.y * -2); }
Vec2 vec2_add(Vec2 a, Vec2 b) { return VEC2(a.x + b.x, a.y + b.y); }
Vec2 vec2_sub(Vec2 a, Vec2 b) { return VEC2(a.x - b.x, a.y - b.y); }

