#include "math/mat4.h"

// clang-format off
Mat4 mat4_identity(void) {
  return (Mat4) {{
      {1, 0, 0, 0},
      {0, 1, 0, 0},
      {0, 0, 1, 0},
      {0, 0, 0, 1}
    }};
}


Mat4 mat4_translate(Mat4 mat, Vec2 vec) {  
  Mat4 translation = {{
      {1, 0, 0, 0},
      {0, 1, 0, 0},
      {0, 0, 1, 0 },
      { vec.x, vec.y, 0, 1}
  }};

  return mat4_mul(mat, translation);
}

// clang-format on
Mat4 mat4_mul(Mat4 a, Mat4 b) {
  Mat4 c = {0};

  for (unsigned int i = 0; i < 4; i++) {
    c.elements[i][0] = (a.elements[i][0] * b.elements[0][0]) +
                       (a.elements[i][1] * b.elements[1][0]) +
                       (a.elements[i][2] * b.elements[2][0]) +
                       (a.elements[i][3] * b.elements[3][0]);

    c.elements[i][1] = (a.elements[i][0] * b.elements[0][1]) +
                       (a.elements[i][1] * b.elements[1][1]) +
                       (a.elements[i][2] * b.elements[2][1]) +
                       (a.elements[i][3] * b.elements[3][1]);

    c.elements[i][2] = (a.elements[i][0] * b.elements[0][2]) +
                       (a.elements[i][1] * b.elements[1][2]) +
                       (a.elements[i][2] * b.elements[2][2]) +
                       (a.elements[i][3] * b.elements[3][2]);

    c.elements[i][3] = (a.elements[i][0] * b.elements[0][3]) +
                       (a.elements[i][1] * b.elements[1][3]) +
                       (a.elements[i][2] * b.elements[2][3]) +
                       (a.elements[i][3] * b.elements[3][3]);
  }

  return c;
}

const float *mat4_ptr(const Mat4 *mat) {
  return &mat->elements[0][0];
}
