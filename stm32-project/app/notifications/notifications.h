#ifndef NOTIFICATIONS_H
#define NOTIFICATIONS_H

#include <stdint.h>
#include <stdbool.h>

bool Notifications_ProcessCommand(char *cmd);
void Notifications_SendNoiseDetected(void);
void Notifications_SendStatusUpdate(void);

#endif
