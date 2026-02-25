#include "main.h"
#include "mic.h"
#include <stdint.h>
#include "stm32f1xx_hal.h"
#include "sound_detector.h"

uint16_t mic_offset = 0;


uint16_t Mic_ReadRaw(void)
{
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
	uint16_t value = HAL_ADC_GetValue(&hadc1);
	HAL_ADC_Stop(&hadc1);

	return value;
}

uint16_t Mic_Init(void)

{
	// Mide el offset del microfono. Asegurar silencio al inicializar el sistema

	uint32_t acc = 0;
	uint16_t calibration_buffer[CALIBRATION_SAMPLES];

	for (int i = 0; i<CALIBRATION_SAMPLES; i++){
		HAL_ADC_Start(&hadc1);
		HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
		calibration_buffer[i] = HAL_ADC_GetValue(&hadc1);
		HAL_ADC_Stop(&hadc1);
		acc+= calibration_buffer[i];
	}

	mic_offset = acc / CALIBRATION_SAMPLES;

	return mic_offset;

}



