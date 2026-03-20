#include "gl/texture.h"
#include <stb_image.h>
#include <stdbool.h>
#include <stdio.h>

Texture texture_from_file(const char *path) {
  // stbi_set_flip_vertically_on_load(true);

  int width, height, channels;
  uint8_t *data = stbi_load(path, &width, &height, &channels, 0);
  if (data == NULL) {
    fprintf(stderr, "dust -> cannot load texture from file: %s\n", path);
    stbi_image_free(data);
    return (Texture){0};
  }

  Texture tex = texture_from_buffer(data, width, height, channels);
  stbi_image_free(data);

  return tex;
}

Texture texture_from_buffer(const uint8_t *buffer, int width, int height,
                            int channels) {
  Texture tex;
  tex.width = width;
  tex.height = height;
  tex.channels = channels;

  GLint format = 0;
  if (channels == 1) {
    format = GL_RED;
  } else if (channels == 3) {
    format = GL_RGB;
  } else if (channels == 4) {
    format = GL_RGBA;
  }

  glGenTextures(1, &tex.id);
  glBindTexture(GL_TEXTURE_2D, tex.id);
  glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format,
               GL_UNSIGNED_BYTE, buffer);
  
  glGenerateMipmap(GL_TEXTURE_2D);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                  GL_LINEAR_MIPMAP_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glBindTexture(GL_TEXTURE_2D, 0);

  return tex;
}

Texture texture_white_1x1(void) {
  return texture_from_buffer((uint8_t[]){255, 255, 255, 255}, 1, 1, 4);
}

void texture_free(Texture *tex) {
  glDeleteTextures(1, &tex->id);
  tex->id = 0;
}

void texture_bind(Texture tex, uint32_t slot) {
  glActiveTexture(GL_TEXTURE0 + slot);
  glBindTexture(GL_TEXTURE_2D, tex.id);
}

void texture_unbind(void) { glBindTexture(GL_TEXTURE_2D, 0); }
