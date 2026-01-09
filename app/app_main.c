#include "app_main.h"
#include "mode_manager.h"

void  App_Init(void)
{
	Mode_Init();
}

void App_Loop(void)
{
	Mode_Update();
}

