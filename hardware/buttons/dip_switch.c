#include "dip_switch.h"
#include "stm32f1xx_hal.h"


#define DIP1_PORT GPIOA
#define DIP1_PIN GPIO_PIN_1

#define DIP2_PORT GPIOA
#define DIP2_PIN GPIO_PIN_4

#define DIP3_PORT GPIOB
#define DIP3_PIN GPIO_PIN_0

uint8_t DipSwitch_Read(void)
{
    uint8_t value = 0;

    if (HAL_GPIO_ReadPin(DIP1_PORT, DIP1_PIN) == GPIO_PIN_RESET)
        value |= (1 << 2);   // desplaza el bit 0 posiciones y se lo suma a value

    if (HAL_GPIO_ReadPin(DIP2_PORT, DIP2_PIN) == GPIO_PIN_RESET)
        value |= (1 << 1);

    if (HAL_GPIO_ReadPin(DIP3_PORT, DIP3_PIN) == GPIO_PIN_RESET)
        value |= (1 << 0);

    return value; // 0–7
}
