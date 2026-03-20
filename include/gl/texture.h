#ifndef DUST_TEXTURE_H
#define DUST_TEXTURE_H

#include <glad/glad.h>
#include <stdint.h>

typedef struct {
  GLuint id;
  int width, height, channels;
} Texture;

Texture texture_from_file(const char *path);
Texture texture_from_buffer(const uint8_t *buffer, int width,
                            int height, int channels);
Texture texture_white_1x1(void);

void texture_free(Texture *tex);
void texture_bind(Texture tex, uint32_t slot);
void texture_unbind(void);

#endif
