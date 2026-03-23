#ifndef CB_PLATFORM_H
#define CB_PLATFORM_H

#include "types.h"

typedef struct {
    void *buffer;
} PlatformState;

CB_API b8 platform_init(PlatformState *state, const char *name, i32 width, i32 height);
b8 platform_poll(PlatformState *state);
b8 platform_shutdown(void);

void *platform_mem_alloc(u64 size);
void platform_mem_free(void *buffer);
void platform_mem_zero(void *buffer, u64 size);
void platform_mem_copy(void *destination, const void *source, u64 size);
void platform_mem_set(void *destination, i32 value, u64 size);

void platform_console_write(const char *message);
void platform_console_write_error(const char *message);

f64 platform_time(void);
void platform_sleep(u64 ms);

#endif