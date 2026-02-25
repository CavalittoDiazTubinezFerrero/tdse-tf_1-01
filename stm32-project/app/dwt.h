#ifndef DWT_H
#define DWT_H

#include "stm32f1xx_hal.h"
#include <stdint.h>

void cycle_counter_init(void);
void cycle_counter_reset(void);
uint32_t cycle_counter_get_time_us(void);

#endif
