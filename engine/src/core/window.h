#ifndef CB_WINDOW_H
#define CB_WINDOW_H

// clang-format off
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "types.h"
// clang-format on

typedef struct {
  const char *title;
  u32 width, height;
  b8 vsync, resizable;
} WindowConfig;

b8 window_open(WindowConfig config);
void window_close(void);

void window_poll_events(void);
void window_swap_buffers(void);

b8 window_should_close(void);
void window_set_title(const char *title);

u32 window_width(void);
u32 window_height(void);

GLFWwindow *window_handle(void);

#endif
