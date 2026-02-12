#include "app_main.h"
#include "mode_manager.h"
#include "sound_detector.h"
#include "stdio.h"
#include "logger.h"
#include "mic.h"
#include "stm32f1xx_hal.h"
#include "main.h"
#include "notifications.h"
#include "bluetooth.h"
#include "led.h"
#include "config.h"
#include "buzzer.h"

void  App_Init(void)
{

	// Calibrar el DC del microfono
	Mic_Init();

	// Setear modo inicial
	Mode_Init();

	// Enviar el historial de alertas
	for (int i = 0; i < ALERT_HISTORY_SIZE; i++)
	{
	    alert_entry_t *e = &g_config.alert_history[i];
	    Notifications_SendAlertHistory(e->text);
	}


}

void App_Loop(void)
{

    Mode_Update();

    if (rx_buffer_ready)
    {
    	rx_buffer_ready = 0;
        Notifications_OnCommand(rx_buffer);
    }

    if (sound_alert_flag)
	{
		sound_alert_flag = 0;
		Notifications_SendNoiseDetected();
	}
}


