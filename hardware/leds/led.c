#include "led.h"
#include "stm32f1xx_hal.h"

#define LED_1_PORT GPIOB
#define LED_1_PIN GPIO_PIN_10

#define LED_2_PORT GPIOB
#define LED_2_PIN GPIO_PIN_4

#define LED_3_PORT GPIOB
#define LED_3_PIN GPIO_PIN_5

#define LED_4_PORT GPIOA
#define LED_4_PIN GPIO_PIN_8

void Leds_Update(system_mode_t mode)
{
	HAL_GPIO_WritePin(LED_1_PORT, LED_1_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_2_PORT, LED_2_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_3_PORT, LED_3_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_4_PORT, LED_4_PIN, GPIO_PIN_SET);

	switch(mode){

		case MODE_IDLE:
			HAL_GPIO_WritePin(LED_4_PORT, LED_4_PIN, GPIO_PIN_RESET);
			break;

		case MODE_DEFAULT:
			HAL_GPIO_WritePin(LED_1_PORT, LED_1_PIN, GPIO_PIN_SET);
			break;

		case MODE_COUNT:
			HAL_GPIO_WritePin(LED_1_PORT, LED_1_PIN, GPIO_PIN_SET);
			break;

		case MODE_DAY:
			HAL_GPIO_WritePin(LED_2_PORT, LED_2_PIN, GPIO_PIN_SET);
			break;

		case MODE_NIGHT:
			HAL_GPIO_WritePin(LED_3_PORT, LED_3_PIN, GPIO_PIN_SET);
			break;



	}

};

void Leds_Init(void)
{
	HAL_GPIO_WritePin(LED_4_PORT, LED_4_PIN, GPIO_PIN_SET);
}
