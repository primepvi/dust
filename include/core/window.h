#ifndef DUST_WINDOW_H
#define DUST_WINDOW_H

// clang-format off
#include <stdbool.h>
#include <stdint.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
// clang-format on

typedef struct {
  const char *title;
  uint32_t width, height;
  bool vsync, resizable;
} WindowConfig;

bool window_open(WindowConfig config);
void window_close(void);

void window_poll_events(void);
void window_swap_buffers(void);

bool window_should_close(void);
void window_set_title(const char *title);

uint32_t window_width(void);
uint32_t window_height(void);

GLFWwindow *window_handle(void);

#endif
