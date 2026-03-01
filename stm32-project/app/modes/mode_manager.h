#ifndef MODE_MANAGER_H
#define MODE_MANAGER_H

#include "config.h"
#include <stdbool.h>

struct led_t;   // declaración adelantada
typedef struct led_t led_t;

void Mode_Init(void);
bool Mode_Update(void);
bool Mode_UpdateRemote(system_mode_t);
system_mode_t Mode_Get(void);
void Mode_UpdateIndicators(system_mode_t mode, led_t *led1, led_t *led2, led_t *led3);

#endif
