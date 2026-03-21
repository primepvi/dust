#include "engine.h"
#include "input.h"
#include "math/utils.h"

static struct {
  f64 prev, time;
  f32 dt;
  bool should_quit;
} _state;

b8 engine_init(WindowConfig cfg) {
  if (!window_open(cfg))
    return false;

  input_init();

  _state.prev = glfwGetTime();
  _state.time = glfwGetTime();
  _state.dt = 0.0f;
  _state.should_quit = false;

  return true;
}

void engine_run(EngineUpdateCallback update, EngineDrawCallback draw) {
  while (!engine_should_quit()) {
    f64 now = glfwGetTime();
    f32 dt = MIN((f32)(now - _state.prev), ENGINE_MAX_DT);
    _state.dt = dt;
    _state.prev = now;
    _state.time += dt;

    input_update();
    window_poll_events();
    update(_state.dt);
    draw();
    window_swap_buffers();
  }
}

void engine_quit(void) { _state.should_quit = true; }
void engine_shutdown(void) { window_close(); }
f32 engine_dt(void) { return _state.dt; }
f64 engine_time(void) { return _state.time; }
b8 engine_should_quit(void) { return _state.should_quit || window_should_close(); }
