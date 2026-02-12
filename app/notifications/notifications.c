#include "notifications.h"
#include "mode_manager.h"
#include "bluetooth.h"
#include "sound_detector.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void Notifications_OnCommand(char *cmd)
{
	// Comando para cambiar el modo
    if (strncmp(cmd, "MODE=", 5) == 0)
    {
        if (strcmp(&cmd[5], "DIA") == 0)
        	Mode_UpdateRemote(MODE_DAY);
        else if (strcmp(&cmd[5], "NOCHE") == 0)
        	Mode_UpdateRemote(MODE_NIGHT);
        else if (strcmp(&cmd[5], "OFF") == 0)
        	Mode_UpdateRemote(MODE_IDLE);
        else if (strcmp(&cmd[5], "DEFAULT") == 0)
        	Mode_UpdateRemote(MODE_DEFAULT);
    }

    // Comando para cambiar el umbral/sensibilidad
    else if (strncmp(cmd, "TH=", 3) == 0)
    {
        uint16_t th = atoi(&cmd[3]);
        SoundDetector_SetThreshold(th);
    }
}


void Notifications_SendConfig(void)
{
    char msg[32];

    snprintf(msg, sizeof(msg),
             "MODE=%d TH=%d\r\n",
             Mode_Get(),
			 SoundDetector_GetThreshold());

    Bluetooth_Send(msg);
}


void Notifications_SendNoiseDetected(void)
{
    Bluetooth_Send("ALERTA\r\n");
    Config_AddAlert("ALERTA\r\n");
}


void Notifications_SendAlertHistory(const char *text)
{
    char buffer[ALERT_TEXT_MAX+7]; // 7 bytes de: HIST, + \n + \0

    // Formato para parsear en la app: HIST,<mensaje>\n
    snprintf(buffer, sizeof(buffer), "HIST,%s\n", text);

    Bluetooth_Send(buffer);
}

