#ifndef DUST_SHADER_H
#define DUST_SHADER_H

#include <glad/glad.h>
#include "../math/mat4.h"

typedef struct {
  GLuint id;
} Shader;

Shader shader_from_files(const char *vertex_path, const char *frag_path);
Shader shader_from_sources(const char *vertex_source, const char *frag_source);

void shader_free(Shader *shader);
void shader_bind(Shader shader);
void shader_unbind(void);

void shader_uniform_mat4(Shader shader, const char *uniform, Mat4 mat);
void shader_uniform_int(Shader shader, const char *uniform, int val);

#endif
