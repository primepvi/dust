// clang-format off
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string.h>
#include <stdio.h>
// clang-format on

#include "input.h"
#include "window.h"

static i32 _key_map[GLFW_KEY_LAST + 1];

static const char *_key_names[KEY_COUNT] = {
#define X(carbon, glfw) [carbon] = #carbon,
    CB_KEYS
#undef X
};

static const i32 _btn_map[MOUSE_COUNT] = {
#define X(carbon, glfw) [carbon] = glfw,
    CB_MOUSE_BUTTONS
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

static void _callback_key(GLFWwindow *w, i32 key, i32 scancode, i32 action,
                          i32 mods) {

  if (key < 0 || key > GLFW_KEY_LAST || _key_map[key] < 0)
    return;

  InputKey input_key = _key_map[key];
  _state.keys_cur[input_key] = (action != GLFW_RELEASE);
}

static void _callback_mouse_btn(GLFWwindow *w, i32 btn, i32 action, i32 mods) {
  if (btn < 0)
    return;

  InputMouseButton mouse_btn = _btn_map[btn];
  _state.btns_cur[mouse_btn] = (action != GLFW_RELEASE);
}

static void _callback_cursor_pos(GLFWwindow *w, f64 x, f64 y) {
  _state.mouse_pos = VEC2((f32)x, (f32)y);
}

static void _callback_scroll(GLFWwindow *w, f64 x_offset, f64 y_offset) {
  _state.scroll_y = (f32)y_offset;
}

void input_init(void) {
  memset(&_state, 0, sizeof(_state));
  memset(_key_map, -1, sizeof(_key_map));
  
  #define X(carbon, glfw) if ((glfw) >= 0) _key_map[glfw] = carbon;
    CB_KEYS
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

b8 input_key_down(InputKey key) {
  return key >= 0 && key < KEY_COUNT && _state.keys_cur[key];
}

b8 input_key_pressed(InputKey key) {
  return key >= 0 && key < KEY_COUNT && _state.keys_cur[key] &&
         !_state.keys_prev[key];
}

b8 input_key_released(InputKey key) {
  return key >= 0 && key < KEY_COUNT && !_state.keys_cur[key] &&
         _state.keys_prev[key];
}

const char *input_key_name(InputKey key) {
  if (key < 0 || key >= KEY_COUNT)
    return "KEY_UNKNOWN";
  return _key_names[key];
}

Vec2 input_mouse_pos(void) { return _state.mouse_pos; }
Vec2 input_mouse_delta(void) {
  return vec2_sub(_state.mouse_pos, _state.mouse_prev);
}

b8 input_mouse_down(InputMouseButton btn) {
  return btn >= 0 && btn < MOUSE_COUNT && _state.btns_cur[btn];
}

b8 input_mouse_pressed(InputMouseButton btn) {
  return btn >= 0 && btn < MOUSE_COUNT && _state.btns_cur[btn] &&
         !_state.btns_prev[btn];
}

b8 input_mouse_released(InputMouseButton btn) {
  return btn >= 0 && btn < MOUSE_COUNT && !_state.btns_cur[btn] &&
         _state.btns_prev[btn];
}

float input_scroll_y(void) { return _state.scroll_y; }
