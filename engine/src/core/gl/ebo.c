#include "ebo.h"

EBO ebo_new(void) {
  EBO ebo = {0};
  glGenBuffers(1, &ebo.id);
  return ebo;
}

void ebo_free(EBO *ebo) {
  glDeleteBuffers(1, &ebo->id);
  ebo->id = 0;
}

void ebo_bind(EBO ebo) { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo.id); }

void ebo_unbind(void) { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }

void ebo_data(EBO ebo, const u32 *indexes, u32 count) {
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint32_t) * count, indexes, GL_STATIC_DRAW);
}
