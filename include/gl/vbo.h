#ifndef DUST_VBO_H
#define DUST_VBO_H

#include <glad/glad.h>
#include <stddef.h>

typedef struct {
  GLuint id;
  GLenum usage;
} VBO;

#define VBO_STATIC vbo_new(GL_STATIC_DRAW)
#define VBO_STREAM vbo_new(GL_SREAM_DRAW)
#define VBO_DYNAMIC vbo_new(GL_DYNAMIC_DRAW)

VBO vbo_new(GLenum usage);
void vbo_free(VBO *vbo);

void vbo_bind(VBO vbo);
void vbo_unbind(void);
void vbo_data(VBO vbo, const void *data, size_t size);

#endif
