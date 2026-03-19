#include "math/mat4.h"
#include <math.h>
#include <stddef.h>

// clang-format off
Mat4 mat4_identity(void) {
  return (Mat4) {{
      1.0f, 0, 0, 0,
      0, 1.0f, 0, 0,
      0, 0, 1.0f, 0,
      0, 0, 0, 1.0f
     }};
}

Mat4 mat4_translate(Mat4 mat, Vec2 vec) {  
  Mat4 translation = {{
      1.0f, 0, 0, 0,
      0, 1.0f, 0, 0,
      0, 0, 1.0f, 0 ,
      vec.x, vec.y, 0, 1.0f
  }};

  return mat4_mul(mat, translation);
}

Mat4 mat4_scale(Mat4 mat, Vec2 scale) {
  Mat4 s = (Mat4){{
      scale.x, 0, 0, 0,
      0, scale.y, 0, 0,
      0, 0, 1.0f, 0,
      0, 0, 0, 1.0f
  }};

  return mat4_mul(mat, s);
}

Mat4 mat4_rotate_z(Mat4 mat, float angle) {
  Mat4 r = (Mat4){{
      cosf(angle), sinf(angle), 0, 0,
      -sinf(angle), cosf(angle), 0, 0,
      0, 0, 1.0f, 0,
      0, 0, 0, 1.0f
  }};

  return mat4_mul(mat, r);
}

Mat4 mat4_mul(Mat4 a, Mat4 b) {
  Mat4 c = {0};

  for (size_t i = 0; i < 4; i++) {
    for (size_t j = 0; j < 4; j++) {
      for (size_t k = 0; k < 4; k++) {
        mat4_index(c, i, j) += mat4_index(a, i, k) * mat4_index(b, k, j);
      }
    }
  }

  return c;
}

Mat4 mat4_ortho(float l, float r, float b, float t) {
  float n = -1.0f;
  float f = 1.0f;
  
  return (Mat4){{
      2/(r-l), 0, 0, 0,
      0, 2/(t-b), 0, 0,
      0, 0, (-2)/(f-n), 0,
      -((r+l)/(r-l)), -((t+b)/(t-b)), -((f+n)/(f-n)), 1
  }};
}

Mat4 mat4_view(Vec2 pos, float z) {
  return (Mat4){{
      z, 0, 0, 0,
      0, z, 0, 0,
      0, 0, 1, 0,
      -pos.x * z, -pos.y * z, 0, 1
  }};
}

const float *mat4_ptr(const Mat4 *mat) { return &mat->data[0]; }
