#include "buzzer.h"


void Buzzer_On(void)
{
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
}

void Buzzer_Off(void)
{
    HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_2);
}

void Buzzer_Beep(uint16_t ms)
{
    Buzzer_On();
    HAL_Delay(ms); // excepcion de codigo bloqueante porque el cambio de estado no ocurre constantemente sino que es un evento puntual.
    Buzzer_Off();
}
