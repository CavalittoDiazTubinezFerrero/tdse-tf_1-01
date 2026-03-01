#include "mode_manager.h"
#include "dip_switch.h"
#include "led.h"
#include "buzzer.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "notifications.h"
#include "config.h"
#include "sound_detector.h"
#include "board.h"

#define DIP_SWITCH_1_ACTIVE 4
#define DIP_SWITCH_2_ACTIVE 2
#define DIP_SWITCH_3_ACTIVE 1


static system_mode_t current_mode = MODE_IDLE;
static system_mode_t last_mode = MODE_IDLE;
static uint8_t last_dip_switch_value = 0;


void Mode_Init(void)
{
	current_mode = MODE_IDLE;
	last_mode = MODE_IDLE;

}


bool Mode_Update(void)
{
	bool mode_changed = false;
	uint8_t dip_switch_value = DipSwitch_Read();

	if (dip_switch_value == last_dip_switch_value)
		return false;

	switch (dip_switch_value)
	{

	case DIP_SWITCH_2_ACTIVE:
		 current_mode = MODE_IDLE;
		 break;

	case DIP_SWITCH_3_ACTIVE:
		 current_mode = MODE_IDLE;
		 break;

	 case DIP_SWITCH_1_ACTIVE:
		 current_mode = MODE_DEFAULT;
		 break;

	 case DIP_SWITCH_1_ACTIVE + DIP_SWITCH_2_ACTIVE:
		 current_mode = MODE_DAY;
		 break;

	 case DIP_SWITCH_1_ACTIVE + DIP_SWITCH_3_ACTIVE:
		 current_mode = MODE_NIGHT;
		 break;

	 case DIP_SWITCH_1_ACTIVE + DIP_SWITCH_2_ACTIVE + DIP_SWITCH_3_ACTIVE:
		 current_mode = MODE_DEFAULT;
		 break;


	 default:
		 current_mode = MODE_IDLE;
		 break;
	}

	// Detectar si cambio de modo
	if (last_mode != current_mode)
	{
		mode_changed = true;
		last_mode = current_mode;
		last_dip_switch_value = dip_switch_value;

	}
	return mode_changed;
}

bool Mode_UpdateRemote(system_mode_t mode)
{
    if (mode >= MODE_COUNT)
        return false;

    if (mode != Mode_Get() && last_mode != MODE_IDLE)
    {
        current_mode = mode;
        return true;
    }

    return false;
}


system_mode_t Mode_Get(void)
{
	return current_mode;
}

void Mode_UpdateIndicators(system_mode_t mode,led_t *led1,led_t *led2,led_t *led3)
{
	Led_SetStatus(led1, LED_OFF);
	Led_SetStatus(led2, LED_OFF);
	Led_SetStatus(led3, LED_OFF);

	switch(mode)
	{
    case MODE_IDLE:

        break;

    case MODE_COUNT:
    case MODE_DEFAULT:
        Led_SetStatus(led1, LED_ON);
        break;

    case MODE_DAY:
        Led_SetStatus(led2, LED_ON);
        break;

    case MODE_NIGHT:
        Led_SetStatus(led3, LED_ON);
        break;
	}

	Led_Update(led1);
	Led_Update(led2);
	Led_Update(led3);

}
