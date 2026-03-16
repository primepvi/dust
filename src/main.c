#include "math/utils.h"
#include "math/vec2.h"
#include <stdio.h>

int main(void) {
  Vec2 a = VEC2(10.0f, 5.0f);
  Vec2 b = VEC2(15.0f, 25.0f);

  printf("a = [%f %f]\n", a.x, a.y);
  printf("b = [%f %f]\n", b.x, b.y);
  printf("\n");

  Vec2 sum = vec2_add(a, b);
  Vec2 sub = vec2_sub(a, b);
  Vec2 neg = vec2_negate(a);
  Vec2 scl = vec2_scale(a, 2.0f);
  printf("a + b    = [%f %f]\n", sum.x, sum.y);
  printf("a - b    = [%f %f]\n", sub.x, sub.y);
  printf("-a       = [%f %f]\n", neg.x, neg.y);
  printf("a * 2    = [%f %f]\n", scl.x, scl.y);
  printf("\n");

  printf("mag(a)   = %f\n", vec2_magnitude(a));
  printf("dist(a,b)= %f\n", vec2_distance(a, b));
  printf("\n");

  Vec2 norm_a = vec2_normalize(a);
  printf("norm(a)  = [%f %f]\n", norm_a.x, norm_a.y);
  printf("mag(norm(a)) = %f (must be 1.0)\n", vec2_magnitude(norm_a));
  printf("\n");

  Vec2 zero = VEC2_ZERO;
  Vec2 norm_z = vec2_normalize(zero);
  printf("norm(zero) = [%f %f] (must be [0 0])\n", norm_z.x, norm_z.y);
  printf("\n");

  printf("dot(a, b) = %f\n", vec2_dot(a, b));
  printf("\n");

  Vec2 a_hat = vec2_normalize(a);
  float sproj = vec2_scalar_projection(a_hat, b);
  Vec2 vproj = vec2_vector_projection(a_hat, b);
  printf("scalar_proj(a_hat, b) = %f\n", sproj);
  printf("vector_proj(a_hat, b) = [%f %f]\n", vproj.x, vproj.y);
  printf("\n");

  float angle_a = vec2_angle(a);
  Vec2 rebuilt = vec2_from_angle(angle_a);
  Vec2 norm_rebuilt = vec2_normalize(a);
  printf("angle(a)              = %f rad / %f deg\n", angle_a,
         RAD2DEG(angle_a));
  printf("from_angle(angle(a))  = [%f %f]\n", rebuilt.x, rebuilt.y);
  printf("norm(a)               = [%f %f] (must be equal)\n", norm_rebuilt.x,
         norm_rebuilt.y);

  return 0;
}
