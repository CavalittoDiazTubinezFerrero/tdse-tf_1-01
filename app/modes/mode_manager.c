#include "mode_manager.h"
#include "dip_switch.h"
#include <stdint.h>

#define DIP_SWITCH_1_ACTIVE 4
#define DIP_SWITCH_2_ACTIVE 2
#define DIP_SWITCH_3_ACTIVE 1


static system_mode_t current_mode = MODE_DEFAULT;


void Mode_Init(void)
{
	current_mode = MODE_DEFAULT;
}


void Mode_Update(void)
{
	uint8_t dip_switch_value = DipSwitch_Read();

	switch (dip_switch_value)
	{
	 case DIP_SWITCH_1_ACTIVE:
		 current_mode = MODE_DEFAULT;
		 break;


	 case DIP_SWITCH_2_ACTIVE:
		 current_mode = MODE_DAY;
		 break;


	 case DIP_SWITCH_1_ACTIVE + DIP_SWITCH_2_ACTIVE:
		 current_mode = MODE_DAY;
		 break;


	 case DIP_SWITCH_3_ACTIVE:
		 current_mode = MODE_NIGHT;
		 break;


	 case DIP_SWITCH_1_ACTIVE + DIP_SWITCH_3_ACTIVE:
		 current_mode = MODE_NIGHT;
		 break;


	 default:
		 current_mode = MODE_DEFAULT;
		 break;


	}
}


