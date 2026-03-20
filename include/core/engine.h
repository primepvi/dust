#ifndef DUST_ENGINE_H
#define DUST_ENGINE_H

#include "window.h"
#define ENGINE_MAX_DT 0.05f

typedef void (*EngineUpdateCallback)(float dt);
typedef void (*EngineDrawCallback)(void);

bool engine_init(WindowConfig cfg);
void engine_run(EngineUpdateCallback update, EngineDrawCallback draw);
void engine_quit(void);
void engine_shutdown(void);

float engine_dt(void);
double engine_time(void);
bool engine_should_quit(void);

#endif
