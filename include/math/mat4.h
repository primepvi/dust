#ifndef DUST_MAT4_H
#define DUST_MAT4_H

#include "vec2.h"
#define mat4_index(mat, row, col) ((mat).data[(col) * 4 + (row)])

// linear column-major matrix
typedef struct {
  float data[16];
} Mat4;

Mat4 mat4_identity(void);
Mat4 mat4_translate(Mat4 mat, Vec2 vec);
Mat4 mat4_scale(Mat4 mat, Vec2 scale);
Mat4 mat4_rotate_z(Mat4 mat, float angle);
Mat4 mat4_mul(Mat4 a, Mat4 b);
Mat4 mat4_ortho(float left, float right, float bottom, float top);
Mat4 mat4_view(Vec2 pos, float zoom);

const float* mat4_ptr(const Mat4 *mat);

#endif
