#ifndef CB_ENGINE_H
#define CB_ENGINE_H

#include "types.h"
#include "window.h"

#define ENGINE_MAX_DT 0.05f

typedef void (*EngineUpdateCallback)(float dt);
typedef void (*EngineDrawCallback)(void);

CB_API b8 engine_init(WindowConfig cfg);
CB_API void engine_run(EngineUpdateCallback update, EngineDrawCallback draw);
CB_API void engine_quit(void);
CB_API void engine_shutdown(void);

CB_API f32 engine_dt(void);
CB_API f64 engine_time(void);
b8 engine_should_quit(void);

#endif
