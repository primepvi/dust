#include <stdlib.h>
#include <core/logger.h>
#include <plaftform/platform.h>

int main(void) {
  CB_INFO("Hello, World");
  PlatformState *state = malloc(sizeof(PlatformState));
  platform_init(state, "Hello, World", 0 , 0);
  CB_INFO("Hello, World");

  return 0;
}
