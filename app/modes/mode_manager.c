#include "mode_manager.h"
#include "dip_switch.h"
#include "led.h"
#include "buzzer.h"
#include <stdint.h>


#define DIP_SWITCH_1_ACTIVE 4
#define DIP_SWITCH_2_ACTIVE 2
#define DIP_SWITCH_3_ACTIVE 1


static system_mode_t current_mode = MODE_IDLE;
static system_mode_t last_mode = MODE_IDLE;

static uint8_t remote_mode_active = 0; // Indica si el modo fue fijado remotamente (app)

void Mode_Init(void)
{
	current_mode = MODE_IDLE;
	last_mode = MODE_IDLE;
}


void Mode_Update(void)
{
	// tiene prioridad la app para setear modos
	if (remote_mode_active)
	    {
	        return;
	    }

	uint8_t dip_switch_value = DipSwitch_Read();


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

	// Detectar si salio de MODE_IDLE
	if (last_mode != current_mode)
	{
		Leds_Update(current_mode);
		if (last_mode == MODE_IDLE && current_mode != MODE_IDLE)
		{
			Buzzer_Beep(200);
		}
		last_mode = current_mode;

	}

}

/* Solicitud del BLE para */
void Mode_UpdateRemote(system_mode_t mode)
{
    if (mode < MODE_COUNT)
    {
        current_mode = mode;
        Leds_Update(MODE_IDLE);  // para evr si se recibe el byte por ble
        remote_mode_active = 1;
    }
}

void Mode_ClearRemote(void)
{
    remote_mode_active = 0;
}

system_mode_t Mode_Get(void)
{
	return current_mode;
}
