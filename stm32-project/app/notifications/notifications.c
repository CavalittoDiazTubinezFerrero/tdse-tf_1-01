#include "notifications.h"
#include "mode_manager.h"
#include "bluetooth.h"
#include "sound_detector.h"
#include "config.h"
#include "logger.h"
#include "stm32f1xx_hal.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

bool Notifications_ProcessCommand(char *cmd)
{
    if (strncmp(cmd, "MODE:{", 6) == 0)
    {
        char *mode = &cmd[6];

        if (strncmp(mode, "DAY}", 4) == 0)
            return Mode_UpdateRemote(MODE_DAY);

        else if (strncmp(mode, "NIGHT}", 6) == 0)
            return Mode_UpdateRemote(MODE_NIGHT);

        else if (strncmp(mode, "IDLE}", 4) == 0)
            return Mode_UpdateRemote(MODE_IDLE);

        else if (strncmp(mode, "DEFAULT}", 8) == 0)
            return Mode_UpdateRemote(MODE_DEFAULT);
    }

    else if (strncmp(cmd, "SENS:", 5) == 0)
    {
        int threshold = atoi(&cmd[5]);

        if (threshold >= 0 && threshold <= TH_MAX_VALUE)
        {
            SoundDetector_SetThreshold((uint16_t)threshold);
        }
    }

    return false;
}



void Notifications_SendStatusUpdate(void)
{
    char buffer[32];

    snprintf(buffer, sizeof(buffer), "STATUS:%sUMBRAL:%d;", Mode_ToString(Mode_Get()) ,SoundDetector_GetThreshold() );
    Bluetooth_Send(buffer);

}

void Notifications_SendNoiseDetected(void)
{
    Bluetooth_Send("ALERTA\r\n;");
}


