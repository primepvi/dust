#include <stdio.h>
#include "math/vec2.h"

int main(void) {
  Vec2 a = VEC2(10.0f, 5.0f);
  Vec2 b = VEC2(15.f, 25.0f);
  printf("a = [%f %f]\n", a.x, a.y);
  printf("b = [%f %f]\n", b.x, b.y);
  
  Vec2 sum = vec2_add(a, b);
  Vec2 sub = vec2_sub(a, b);
  printf("a + b = [%f %f]\n", sum.x, sum.y);
  printf("a - b = [%f %f]\n", sub.x, sub.y);

  Vec2 neg_a = vec2_neg(a);
  printf("-a = [%f %f]\n", neg_a.x, neg_a.y);

  return 0;
}
