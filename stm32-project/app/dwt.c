#include "dwt.h"

static uint32_t cpu_freq_hz = 0;

void cycle_counter_init(void)
{
    /* Enable TRC */
    CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;

    /* Reset cycle counter */
    DWT->CYCCNT = 0;

    /* Enable cycle counter */
    DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;

    cpu_freq_hz = SystemCoreClock;
}

void cycle_counter_reset(void)
{
    DWT->CYCCNT = 0;
}

uint32_t cycle_counter_get_time_us(void)
{
    uint32_t cycles = DWT->CYCCNT;

    return cycles / (cpu_freq_hz / 1000000);
}
