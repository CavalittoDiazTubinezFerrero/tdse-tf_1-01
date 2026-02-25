#include "led.h"
#include "stm32f1xx_hal.h"


void Led_Init(led_t *led, GPIO_TypeDef *port, uint16_t pin)
{
    led->port = port;
    led->pin = pin;
    led->status = LED_OFF;
    led->last_toggle = 0;
    led->state = 0;
}

void Led_SetStatus(led_t *led, led_status_t status)
{
    led->status = status;
}

void Led_Update(led_t *led)
{
    switch(led->status)
    {
        case LED_OFF:
            HAL_GPIO_WritePin(led->port, led->pin, GPIO_PIN_RESET);
            break;

        case LED_ON:
            HAL_GPIO_WritePin(led->port, led->pin, GPIO_PIN_SET);
            break;

        case LED_BLINK:
            if (HAL_GetTick() - led->last_toggle >= 500)
            {
                led->last_toggle = HAL_GetTick();
                led->state = !led->state;

                HAL_GPIO_WritePin(led->port, led->pin,
                    led->state ? GPIO_PIN_SET : GPIO_PIN_RESET);
            }
            break;
    }
}




