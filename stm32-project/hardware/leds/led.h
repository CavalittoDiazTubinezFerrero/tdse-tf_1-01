#ifndef LED_H
#define LED_H

#include "mode_manager.h"
#include "stm32f1xx_hal.h"

typedef enum {
    LED_OFF,
    LED_ON,
    LED_BLINK
} led_status_t;

typedef struct led_t{
    GPIO_TypeDef *port;
    uint16_t pin;
    led_status_t status;
    uint32_t last_toggle;
    uint8_t state;
} led_t;

void Led_Init(led_t *led, GPIO_TypeDef *port, uint16_t pin);
void Led_SetStatus(led_t *led, led_status_t status);
void Led_Update(led_t *led);

#endif
