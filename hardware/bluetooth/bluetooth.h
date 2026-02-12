#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include <stdint.h>

#define RX_BUFFER_SIZE 64

extern volatile uint8_t rx_buffer_ready;
extern char rx_buffer[RX_BUFFER_SIZE];

void Bluetooth_Init(void);
void Bluetooth_Send(const char *msg);
void Bluetooth_OnRxByte(uint8_t byte);

#endif
