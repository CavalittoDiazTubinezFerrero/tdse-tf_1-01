/* No decide nada, solo pasa strings */
/* Acumula bytes hasta \n */
#include "main.h"
#include "bluetooth.h"
#include "notifications.h"
#include "stm32f1xx_hal.h"
#include <string.h>

char rx_buffer[RX_BUFFER_SIZE];
static uint8_t rx_index = 0;
volatile uint8_t rx_buffer_ready = 0;

void Bluetooth_Init(void)
{
    rx_index = 0;
    memset(rx_buffer, 0, sizeof(rx_buffer));
}


void Bluetooth_Send(const char *msg)
{
    if (msg == NULL)
        return;

    HAL_UART_Transmit(&huart1, (uint8_t *)msg, strlen(msg), 1000);
}


void Bluetooth_OnRxByte(uint8_t byte)
{

    if (byte == '\n')
    {
        rx_buffer[rx_index] = '\0';   // fin de string

        if (rx_index > 0)
        {
        	rx_buffer_ready = 1;
        }

        rx_index = 0;
        return;
    }

    if (rx_index < RX_BUFFER_SIZE - 1)
    {
        rx_buffer[rx_index++] = (char)byte;
    }
    else
    {
        rx_index = 0; // overflow: descartamos
    }
}
