#include <core/window.h>
#include <core/engine.h>
#include <core/input.h>
#include <core/logger.h>

void update(f32 dt) {
  if (input_key_pressed(KEY_ESCAPE))
    engine_quit();
}

void draw(void) {}

int main(void) {
  WindowConfig config = {
      .width = 1080, .height = 720, .resizable = true, .title = "dust."};

  if (!engine_init(config))
    return 1;

  engine_run(update, draw);
  engine_shutdown();
  CB_INFO("Engine Shutdown");

  return 0;
}
