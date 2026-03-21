#ifndef CB_INPUT_H
#define CB_INPUT_H

#include "types.h"
#include "./math/vec2.h"
#include <stdbool.h>

#define CB_KEYS                                                              \
  /* letters */                                                                \
  X(KEY_UNKNOWN, GLFW_KEY_UNKNOWN)							\
  X(KEY_A, GLFW_KEY_A)                                                         \
  X(KEY_B, GLFW_KEY_B)                                                         \
  X(KEY_C, GLFW_KEY_C)                                                         \
  X(KEY_D, GLFW_KEY_D)                                                         \
  X(KEY_E, GLFW_KEY_E)                                                         \
  X(KEY_F, GLFW_KEY_F)                                                         \
  X(KEY_G, GLFW_KEY_G)                                                         \
  X(KEY_H, GLFW_KEY_H)                                                         \
  X(KEY_I, GLFW_KEY_I)                                                         \
  X(KEY_J, GLFW_KEY_J)                                                         \
  X(KEY_K, GLFW_KEY_K)                                                         \
  X(KEY_L, GLFW_KEY_L)                                                         \
  X(KEY_M, GLFW_KEY_M)                                                         \
  X(KEY_N, GLFW_KEY_N)                                                         \
  X(KEY_O, GLFW_KEY_O)                                                         \
  X(KEY_P, GLFW_KEY_P)                                                         \
  X(KEY_Q, GLFW_KEY_Q)                                                         \
  X(KEY_R, GLFW_KEY_R)                                                         \
  X(KEY_S, GLFW_KEY_S)                                                         \
  X(KEY_T, GLFW_KEY_T)                                                         \
  X(KEY_U, GLFW_KEY_U)                                                         \
  X(KEY_V, GLFW_KEY_V)                                                         \
  X(KEY_W, GLFW_KEY_W)                                                         \
  X(KEY_X, GLFW_KEY_X)                                                         \
  X(KEY_Y, GLFW_KEY_Y)                                                         \
  X(KEY_Z, GLFW_KEY_Z)                                                         \
  /* numbers */                                                                \
  X(KEY_0, GLFW_KEY_0)                                                         \
  X(KEY_1, GLFW_KEY_1)                                                         \
  X(KEY_2, GLFW_KEY_2)                                                         \
  X(KEY_3, GLFW_KEY_3)                                                         \
  X(KEY_4, GLFW_KEY_4)                                                         \
  X(KEY_5, GLFW_KEY_5)                                                         \
  X(KEY_6, GLFW_KEY_6)                                                         \
  X(KEY_7, GLFW_KEY_7)                                                         \
  X(KEY_8, GLFW_KEY_8)                                                         \
  X(KEY_9, GLFW_KEY_9)                                                         \
  /* control keys */                                                           \
  X(KEY_ESCAPE, GLFW_KEY_ESCAPE)                                               \
  X(KEY_ENTER, GLFW_KEY_ENTER)                                                 \
  X(KEY_TAB, GLFW_KEY_TAB)                                                     \
  X(KEY_BACKSPACE, GLFW_KEY_BACKSPACE)                                         \
  X(KEY_SPACE, GLFW_KEY_SPACE)                                                 \
  X(KEY_CAPS_LOCK, GLFW_KEY_CAPS_LOCK)                                         \
  /* modifiers */                                                              \
  X(KEY_SHIFT_LEFT, GLFW_KEY_LEFT_SHIFT)                                       \
  X(KEY_SHIFT_RIGHT, GLFW_KEY_RIGHT_SHIFT)                                     \
  X(KEY_CTRL_LEFT, GLFW_KEY_LEFT_CONTROL)                                      \
  X(KEY_CTRL_RIGHT, GLFW_KEY_RIGHT_CONTROL)                                    \
  X(KEY_ALT_LEFT, GLFW_KEY_LEFT_ALT)                                           \
  X(KEY_ALT_RIGHT, GLFW_KEY_RIGHT_ALT)                                         \
  /* navigation keys */                                                        \
  X(KEY_UP, GLFW_KEY_UP)                                                       \
  X(KEY_DOWN, GLFW_KEY_DOWN)                                                   \
  X(KEY_LEFT, GLFW_KEY_LEFT)                                                   \
  X(KEY_RIGHT, GLFW_KEY_RIGHT)                                                 \
  X(KEY_PAGE_UP, GLFW_KEY_PAGE_UP)                                             \
  X(KEY_PAGE_DOWN, GLFW_KEY_PAGE_DOWN)                                         \
  X(KEY_HOME, GLFW_KEY_HOME)                                                   \
  X(KEY_END, GLFW_KEY_END)                                                     \
  X(KEY_INSERT, GLFW_KEY_INSERT)                                               \
  X(KEY_DELETE, GLFW_KEY_DELETE)                                               \
  /* function keys */                                                          \
  X(KEY_F1, GLFW_KEY_F1)                                                       \
  X(KEY_F2, GLFW_KEY_F2)                                                       \
  X(KEY_F3, GLFW_KEY_F3)                                                       \
  X(KEY_F4, GLFW_KEY_F4)                                                       \
  X(KEY_F5, GLFW_KEY_F5)                                                       \
  X(KEY_F6, GLFW_KEY_F6)                                                       \
  X(KEY_F7, GLFW_KEY_F7)                                                       \
  X(KEY_F8, GLFW_KEY_F8)                                                       \
  X(KEY_F9, GLFW_KEY_F9)                                                       \
  X(KEY_F10, GLFW_KEY_F10)                                                     \
  X(KEY_F11, GLFW_KEY_F11)                                                     \
  X(KEY_F12, GLFW_KEY_F12)                                                     \
  /* numpad keys  */                                                           \
  X(KEY_NP_0, GLFW_KEY_KP_0)                                                   \
  X(KEY_NP_1, GLFW_KEY_KP_1)                                                   \
  X(KEY_NP_2, GLFW_KEY_KP_2)                                                   \
  X(KEY_NP_3, GLFW_KEY_KP_3)                                                   \
  X(KEY_NP_4, GLFW_KEY_KP_4)                                                   \
  X(KEY_NP_5, GLFW_KEY_KP_5)                                                   \
  X(KEY_NP_6, GLFW_KEY_KP_6)                                                   \
  X(KEY_NP_7, GLFW_KEY_KP_7)                                                   \
  X(KEY_NP_8, GLFW_KEY_KP_8)                                                   \
  X(KEY_NP_9, GLFW_KEY_KP_9)                                                   \
  X(KEY_NP_ADD, GLFW_KEY_KP_ADD)                                               \
  X(KEY_NP_SUB, GLFW_KEY_KP_SUBTRACT)                                          \
  X(KEY_NP_MUL, GLFW_KEY_KP_MULTIPLY)                                          \
  X(KEY_NP_DIV, GLFW_KEY_KP_DIVIDE)                                            \
  X(KEY_NP_ENTER, GLFW_KEY_KP_ENTER)                                           \
  X(KEY_NP_DECIMAL, GLFW_KEY_KP_DECIMAL)

#define CB_MOUSE_BUTTONS                                                     \
  X(MOUSE_LEFT, GLFW_MOUSE_BUTTON_LEFT)                                        \
  X(MOUSE_RIGHT, GLFW_MOUSE_BUTTON_RIGHT)                                      \
  X(MOUSE_MIDDLE, GLFW_MOUSE_BUTTON_MIDDLE)

typedef enum {
#define X(carbon, glfw) carbon,
  CB_KEYS
#undef X
      KEY_COUNT
} InputKey;

typedef enum {
#define X(carbon, glfw) carbon,
  CB_MOUSE_BUTTONS
#undef X
      MOUSE_COUNT
} InputMouseButton;

CB_API void input_init(void);
CB_API void input_update(void);

CB_API b8 input_key_down(InputKey key);
CB_API b8 input_key_pressed(InputKey key);
CB_API b8 input_key_released(InputKey key);

CB_API const char *input_key_name(InputKey key);

CB_API Vec2 input_mouse_pos(void);
CB_API Vec2 input_mouse_delta(void);

CB_API b8 input_mouse_down(InputMouseButton btn);
CB_API b8 input_mouse_pressed(InputMouseButton btn);
CB_API b8 input_mouse_released(InputMouseButton btn);

CB_API f32 input_scroll_y(void);

#endif
