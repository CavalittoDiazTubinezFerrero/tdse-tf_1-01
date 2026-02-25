#ifndef SOUND_DETECTOR_H
#define SOUND_DETECTOR_H

#include <stdint.h>
#include <stdbool.h>

extern volatile uint8_t sound_alert_flag;

uint16_t SoundDetector_GetThreshold(void);
bool Sound_IsDetected(uint16_t, uint16_t);
void SoundDetector_SetThreshold(uint16_t);

#endif
