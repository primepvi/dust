// clang-format off
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string.h>
#include <stdio.h>
// clang-format on

#include "core/input.h"
#include "core/window.h"

static int _key_map[GLFW_KEY_LAST + 1];

static const char *_key_names[KEY_COUNT] = {
#define X(dust, glfw) [dust] = #dust,
    DUST_KEYS
#undef X
};

static const int _btn_map[MOUSE_COUNT] = {
#define X(dust, glfw) [dust] = glfw,
    DUST_MOUSE_BUTTONS
#undef X
};

static struct {
  bool keys_cur[KEY_COUNT];
  bool keys_prev[KEY_COUNT];
  bool btns_cur[MOUSE_COUNT];
  bool btns_prev[MOUSE_COUNT];
  Vec2 mouse_pos, mouse_prev;
  float scroll_y;
} _state;

static void _callback_key(GLFWwindow *w, int key, int scancode, int action,
                          int mods) {

  if (key < 0 || key > GLFW_KEY_LAST || _key_map[key] < 0)
    return;

  DustKey dust_key = _key_map[key];
  _state.keys_cur[dust_key] = (action != GLFW_RELEASE);
}

static void _callback_mouse_btn(GLFWwindow *w, int btn, int action, int mods) {
  if (btn < 0)
    return;

  DustMouseButton dust_btn = _btn_map[btn];
  _state.btns_cur[dust_btn] = (action != GLFW_RELEASE);
}

static void _callback_cursor_pos(GLFWwindow *w, double x, double y) {
  _state.mouse_pos = VEC2((float)x, (float)y);
}

static void _callback_scroll(GLFWwindow *w, double x_offset, double y_offset) {
  _state.scroll_y = (float)y_offset;
}

void input_init(void) {
  memset(&_state, 0, sizeof(_state));
  memset(_key_map, -1, sizeof(_key_map));
  #define X(dust, glfw) if ((glfw) >= 0) _key_map[glfw] = dust;
    DUST_KEYS
  #undef X  

  GLFWwindow *w = window_handle();
  glfwSetKeyCallback(w, _callback_key);
  glfwSetMouseButtonCallback(w, _callback_mouse_btn);
  glfwSetCursorPosCallback(w, _callback_cursor_pos);
  glfwSetScrollCallback(w, _callback_scroll);
}

void input_update(void) {
  memcpy(_state.keys_prev, _state.keys_cur, sizeof(_state.keys_cur));
  memcpy(_state.btns_prev, _state.btns_cur, sizeof(_state.btns_cur));
  _state.mouse_prev = _state.mouse_pos;
  _state.scroll_y = 0.0f;
}

bool input_key_down(DustKey key) {
  return key >= 0 && key < KEY_COUNT && _state.keys_cur[key];
}

bool input_key_pressed(DustKey key) {
  return key >= 0 && key < KEY_COUNT && _state.keys_cur[key] &&
         !_state.keys_prev[key];
}

bool input_key_released(DustKey key) {
  return key >= 0 && key < KEY_COUNT && !_state.keys_cur[key] &&
         _state.keys_prev[key];
}

const char *input_key_name(DustKey key) {
  if (key < 0 || key >= KEY_COUNT)
    return "KEY_UNKNOWN";
  return _key_names[key];
}

Vec2 input_mouse_pos(void) { return _state.mouse_pos; }
Vec2 input_mouse_delta(void) {
  return vec2_sub(_state.mouse_pos, _state.mouse_prev);
}

bool input_mouse_down(DustMouseButton btn) {
  return btn >= 0 && btn < MOUSE_COUNT && _state.btns_cur[btn];
}

bool input_mouse_pressed(DustMouseButton btn) {
  return btn >= 0 && btn < MOUSE_COUNT && _state.btns_cur[btn] &&
         !_state.btns_prev[btn];
}

bool input_mouse_released(DustMouseButton btn) {
  return btn >= 0 && btn < MOUSE_COUNT && !_state.btns_cur[btn] &&
         _state.btns_prev[btn];
}

float input_scroll_y(void) { return _state.scroll_y; }
