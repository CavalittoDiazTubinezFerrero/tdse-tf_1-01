#include "sound_detector.h"
#include "mic.h"
#include "mode_manager.h"
#include "logger.h"
#include "config.h"

volatile uint8_t sound_alert_flag = 0;



uint16_t SoundDetector_GetThreshold(void)
{
	system_mode_t mode = Mode_Get();

	if (mode >= MODE_COUNT)
		return g_config.threshold_by_mode[MODE_DEFAULT];

	return g_config.threshold_by_mode[mode];
}


bool Sound_IsDetected(uint16_t adc_value, uint16_t mic_offset)
{

	uint16_t threshold = SoundDetector_GetThreshold();
	uint16_t diff;

	if (adc_value >= mic_offset)
		diff = adc_value - mic_offset;
	else
		diff = mic_offset - adc_value;

	return (diff > threshold);
}

void SoundDetector_SetThreshold(uint16_t threshold)
{
    if (threshold > 250)
    	threshold = 250;

    system_mode_t mode = Mode_Get();

    if (mode < MODE_COUNT)
    {
    	g_config.threshold_by_mode[mode] = threshold;
    	Config_Save();
    }
}
