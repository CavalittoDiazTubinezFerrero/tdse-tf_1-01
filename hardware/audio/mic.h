#ifndef MIC_H
#define MIC_H

#include "stdint.h"

#define CALIBRATION_SAMPLES 1024 // cantidad de muestras para setear el offset del mic

extern uint16_t mic_offset;

uint16_t Mic_ReadRaw(void);

uint16_t Mic_Init(void);

#endif
