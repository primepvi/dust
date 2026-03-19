#ifndef DUST_EBO_H
#define DUST_EBO_H

#include <glad/glad.h>
#include <stdint.h>

typedef struct {
  GLuint id;
} EBO;

EBO ebo_new(void);
void ebo_free(EBO *ebo);

void ebo_bind(EBO ebo);
void ebo_unbind(void);

void ebo_data(EBO ebo, const uint32_t *indexes, uint32_t count);

#endif
