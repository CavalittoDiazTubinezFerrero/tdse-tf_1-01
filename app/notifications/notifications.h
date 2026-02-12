#ifndef NOTIFICATIONS_H
#define NOTIFICATIONS_H

#include <stdint.h>

void Notifications_OnCommand(char *cmd);
void Notifications_SendNoiseDetected(void);
void Notifications_SendConfig(void);
void Notifications_SendAlertHistory(const char *text);

#endif
