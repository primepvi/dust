#ifndef DUST_VAO_H
#define DUST_VAO_H

#include <glad/glad.h>
#include <stddef.h>

typedef struct {
  GLuint id;
} VAO;

VAO vao_new(void);
void vao_free(VAO *vao);

void vao_bind(VAO vao);
void vao_unbind(void);

void vao_attrib(VAO vao, size_t index, size_t count, GLenum type, size_t stride, size_t offset);

#endif
