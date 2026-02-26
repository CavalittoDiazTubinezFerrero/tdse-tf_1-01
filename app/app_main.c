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
#include "dwt.h"
#include <stdbool.h>
#include "board.h"


static led_t led1;
static led_t led2;
static led_t led3;
static led_t led_status;

uint32_t wcet_mode_update = 0;
uint32_t wcet_receive_status = 0;
uint32_t wcet_send_status = 0;
uint32_t wcet_send_alert = 0;
uint32_t wcet_leds_update = 0;
static uint32_t last_alert_time = 0;

void  App_Init(void)
{
	Mic_Init();		// Calibrar el DC del microfono
	Mode_Init();	// Setear modo inicial

	Led_Init(&led1, LED_1_PORT, LED_1_PIN);		// Led rojo
	Led_Init(&led2, LED_2_PORT, LED_2_PIN);		// Led amarillo
	Led_Init(&led3, LED_3_PORT, LED_3_PIN);		// Led azul
	Led_Init(&led_status, LED_STATUS_PORT, LED_STATUS_PIN);		// Led verde

	// Estado inicial de los LEDs apagados
	Led_SetStatus(&led1, LED_OFF);
	Led_SetStatus(&led2, LED_OFF);
	Led_SetStatus(&led3, LED_OFF);
	Led_SetStatus(&led_status, LED_OFF);

	// Cambio fisico de los leds
    Led_Update(&led1);
    Led_Update(&led2);
    Led_Update(&led3);
    Led_Update(&led_status);

    ble_connected = Bluetooth_IsConnected();

}


void App_Loop(void)
{
	system_mode_t last_mode = Mode_Get();
	bool mode_changed;
	bool remote_mode_changed;

	// verificar si se recibio un cambio de modo por el switch
    mode_changed = Mode_Update();

	if(mode_changed)
	{
		Notifications_SendStatusUpdate();
		Mode_UpdateIndicators(Mode_Get(), &led1, &led2, &led3);

		// Detectar si salio de MODE_IDLE
		if (last_mode == MODE_IDLE && Mode_Get() != MODE_IDLE)
		{
			Buzzer_Beep(200);
		}
	}


	// verificar si se recibio un cambio de modo por la app
    if (rx_buffer_ready)
    {
    	rx_buffer_ready = 0;

		remote_mode_changed = Notifications_ProcessCommand(rx_buffer);

		if (remote_mode_changed && last_mode != MODE_IDLE)
		{
			Notifications_SendStatusUpdate();
			Mode_UpdateIndicators(Mode_Get(), &led1, &led2, &led3);
			last_mode = Mode_Get();
		}
    }

    // verificar si se detectó un sonido
    if (sound_alert_flag && Mode_Get() != MODE_IDLE && Bluetooth_IsConnected())
	{
		uint32_t now = HAL_GetTick();
		if ((now - last_alert_time) >= ALERT_COOLDOWN_MS)
		    {
				sound_alert_flag = 0;
				Notifications_SendNoiseDetected();
		        last_alert_time = now;
		    }

	}

    App_UpdateStatusIndicator();
}

void App_UpdateStatusIndicator(void)
{
    if (Mode_Get() == MODE_IDLE)
    {
        Led_SetStatus(&led_status, LED_OFF);
        Led_Update(&led_status);
        return;
    }

    if (Bluetooth_IsConnected())
    {
        Led_SetStatus(&led_status, LED_ON);
        Led_Update(&led_status);
    }
    else
    {
        Led_SetStatus(&led_status, LED_BLINK);
        Led_Update(&led_status);
    }

}

void App_Loop_Test(void)
{
	uint32_t time_us;
	system_mode_t last_mode = Mode_Get();
	bool mode_changed;
	bool remote_mode_changed;

	// verificar si se recibio un cambio de modo por el switch
	cycle_counter_reset();
    mode_changed = Mode_Update();
    time_us = cycle_counter_get_time_us();
	if (time_us > wcet_mode_update)
		wcet_mode_update = time_us;

	if(mode_changed)
	{
		cycle_counter_reset();
		Notifications_SendStatusUpdate();
		time_us = cycle_counter_get_time_us();
		if (time_us > wcet_send_status)
			wcet_send_status = time_us;

		cycle_counter_reset();
		Mode_UpdateIndicators(Mode_Get(), &led1, &led2, &led3);
		time_us = cycle_counter_get_time_us();
		if (time_us > wcet_leds_update)
			wcet_leds_update = time_us;

		// Detectar si salio de MODE_IDLE
		if (last_mode == MODE_IDLE && Mode_Get() != MODE_IDLE)
		{
			Buzzer_Beep(200);
		}
	}


	// verificar si se recibio un cambio de modo por la app
    if (rx_buffer_ready)
    {
    	rx_buffer_ready = 0;

    	cycle_counter_reset();
		remote_mode_changed = Notifications_ProcessCommand(rx_buffer);
		time_us = cycle_counter_get_time_us();
		if (time_us > wcet_receive_status)
			wcet_receive_status = time_us;


		if (remote_mode_changed && last_mode != MODE_IDLE)
		{
			cycle_counter_reset();
			Notifications_SendStatusUpdate();
			time_us = cycle_counter_get_time_us();
			if (time_us > wcet_send_status)
				wcet_send_status = time_us;

			cycle_counter_reset();
			Mode_UpdateIndicators(Mode_Get(), &led1, &led2, &led3);
			time_us = cycle_counter_get_time_us();
			if (time_us > wcet_leds_update)
				wcet_leds_update = time_us;

			last_mode = Mode_Get();
		}

    }

    // verificar si se detectó un sonido
    if (sound_alert_flag && Mode_Get() != MODE_IDLE && Bluetooth_IsConnected())
	{
		uint32_t now = HAL_GetTick();
		if ((now - last_alert_time) >= ALERT_COOLDOWN_MS)
		    {
				sound_alert_flag = 0;

				cycle_counter_reset();
				Notifications_SendNoiseDetected();
				time_us = cycle_counter_get_time_us();
				if (time_us > wcet_send_alert)
					wcet_send_alert = time_us;

		        last_alert_time = now;
		    }

	}

    App_UpdateStatusIndicator();
}
