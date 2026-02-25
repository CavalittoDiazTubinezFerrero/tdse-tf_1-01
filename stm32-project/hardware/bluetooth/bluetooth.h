#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include <stdint.h>

#define RX_BUFFER_SIZE 64

extern volatile uint8_t rx_buffer_ready;
extern volatile uint8_t ble_connected;
extern char rx_buffer[RX_BUFFER_SIZE];

void Bluetooth_Send(const char *msg);
void Bluetooth_OnRxByte(uint8_t byte);
void Bluetooth_OnConnectionChange(uint8_t status);
uint8_t Bluetooth_IsConnected(void);

#endif
