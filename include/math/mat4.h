#ifndef DUST_MAT4_H
#define DUST_MAT4_H

#include "vec2.h"

typedef struct {
  float elements[4][4];
} Mat4;

Mat4 mat4_identity(void);
Mat4 mat4_translate(Mat4 mat, Vec2 vec);
Mat4 mat4_mul(Mat4 a, Mat4 b);

const float* mat4_ptr(const Mat4 *mat);

#endif
