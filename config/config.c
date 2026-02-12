#include "config.h"
#include <string.h>
#include "main.h"

#define CONFIG_FLASH_ADDRESS  0x0801FC00  // última página (F103RB)
#define CONFIG_MAGIC          0xA5A5A5A5

system_config_t g_config;

static void Config_SetDefaults(void)
{
	// umbrales
    g_config.threshold_by_mode[MODE_DAY]     = 150;
    g_config.threshold_by_mode[MODE_NIGHT]   = 70;
    g_config.threshold_by_mode[MODE_DEFAULT] = 100;
    g_config.threshold_by_mode[MODE_IDLE]    = 250;

    // historial de alertas
    for (int i = 0; i < ALERT_HISTORY_SIZE; i++)
    {
        g_config.alert_history[i].text[0] = '\0';
    }
    g_config.alert_index = 0;


    g_config.magic = CONFIG_MAGIC;
}

static uint8_t Config_IsValid(const system_config_t *cfg)
{
    if (cfg->magic != CONFIG_MAGIC)
        return 0;

    for (int i = 0; i < MODE_COUNT; i++)
    {
        if (cfg->threshold_by_mode[i] > 4095)
            return 0;
    }

    return 1;
}

void Config_Init(void)
{
    memcpy(&g_config, (void *)CONFIG_FLASH_ADDRESS, sizeof(system_config_t));

    if (!Config_IsValid(&g_config))
    {
        Config_SetDefaults();
        Config_Save();
    }
}

void Config_Save(void)
{
    HAL_FLASH_Unlock();

    FLASH_EraseInitTypeDef erase = {
        .TypeErase   = FLASH_TYPEERASE_PAGES,
        .PageAddress = CONFIG_FLASH_ADDRESS,
        .NbPages     = 1
    };

    uint32_t error;
    HAL_FLASHEx_Erase(&erase, &error);

    uint32_t *data = (uint32_t *)&g_config;
    for (uint32_t i = 0; i < sizeof(system_config_t) / 4; i++)
    {
        HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD,
                          CONFIG_FLASH_ADDRESS + i * 4,
                          data[i]);
    }

    HAL_FLASH_Lock();
}

void Config_AddAlert(const char *text)
{
    uint8_t i = g_config.alert_index;

    strncpy(g_config.alert_history[i].text, text, ALERT_TEXT_MAX - 1);
    g_config.alert_history[i].text[ALERT_TEXT_MAX - 1] = '\0';

    g_config.alert_index = (i + 1) % ALERT_HISTORY_SIZE;

    Config_Save();
}
