#include "gl/vao.h"

VAO vao_new(void) {
  VAO vao = {0};
  glGenVertexArrays(1, &vao.id);

  return vao;
}

void vao_free(VAO *vao) {
  glDeleteVertexArrays(1, &vao->id);
  vao->id = 0;
}

void vao_bind(VAO vao) { glBindVertexArray(vao.id); }
void vao_unbind(void) { glBindVertexArray(0); }

void vao_attrib(VAO vao, size_t index, size_t count, GLenum type, size_t stride,
                size_t offset) {
  glVertexAttribPointer(index, count, type, GL_FALSE, stride, (void *)offset);
  glEnableVertexAttribArray(index);
}
