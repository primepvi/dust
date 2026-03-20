#include "core/engine.h"
#include "core/input.h"
#include "math/utils.h"

static struct {
  double prev;
  double time;
  float dt;
  bool should_quit;
} _state;

bool engine_init(WindowConfig cfg) {
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
    double now = glfwGetTime();
    float dt = MIN((float)(now - _state.prev), ENGINE_MAX_DT);
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
float engine_dt(void) { return _state.dt; }
double engine_time(void) { return _state.time; }
bool engine_should_quit(void) { return _state.should_quit || window_should_close(); }
