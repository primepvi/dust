#include "core/window.h"
#include <stdio.h>

static struct {
  GLFWwindow *handle;
  uint32_t width, height;
} _state;

static void _callback_framebuffer_resize(GLFWwindow *w, int width, int height) {
  _state.width = width;
  _state.height = height;
  glViewport(0, 0, width, height);
}

bool window_open(WindowConfig config) {
  if (!glfwInit()) {
    fprintf(stderr, "dust -> cannot initialize glfw.\n");
    return false;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, config.resizable ? GLFW_TRUE : GLFW_FALSE);

  _state.handle =
      glfwCreateWindow(config.width, config.height, config.title, NULL, NULL);
  if (!_state.handle) {
    fprintf(stderr, "dust -> cannot open window.\n");
    glfwTerminate();
    return false;
  }

  _state.width = config.width;
  _state.height = config.height;

  glfwMakeContextCurrent(_state.handle);
  glfwSwapInterval(config.vsync ? 1 : 0);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    fprintf(stderr, "dust -> cannot load glad.\n");
    glfwDestroyWindow(_state.handle);
    glfwTerminate();
    return false;
  }

  glfwSetFramebufferSizeCallback(_state.handle, _callback_framebuffer_resize);
  glViewport(0, 0, _state.width, _state.height);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  return true;
}

void window_close(void) {
  glfwDestroyWindow(_state.handle);
  glfwTerminate();
  _state.handle = NULL;
}

void window_poll_events(void) { glfwPollEvents(); }
void window_swap_buffers(void) { glfwSwapBuffers(_state.handle); }

bool window_should_close(void) { return glfwWindowShouldClose(_state.handle); }
void window_set_title(const char *title) {
  glfwSetWindowTitle(_state.handle, title);
}

uint32_t window_width(void) { return _state.width; }
uint32_t window_height(void) { return _state.height; }

GLFWwindow *window_handle(void) { return _state.handle; }
		      
