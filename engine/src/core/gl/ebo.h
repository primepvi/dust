#ifndef CB_EBO_H
#define CB_EBO_H

#include <glad/glad.h>
#include "types.h"

typedef struct {
  GLuint id;
} EBO;

EBO ebo_new(void);
void ebo_free(EBO *ebo);

void ebo_bind(EBO ebo);
void ebo_unbind(void);

void ebo_data(EBO ebo, const u32 *indexes, u32 count);

#endif
