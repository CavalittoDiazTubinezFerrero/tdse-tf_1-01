#ifndef CONFIG_H
#define CONFIG_H

#include <stdint.h>

#define ALERT_TEXT_MAX 32
#define TH_MAX_VALUE 500
#define ALERT_COOLDOWN_MS 4000

typedef struct
{
    char text[ALERT_TEXT_MAX];
} alert_entry_t;

typedef enum
{
    MODE_DAY = 0,
    MODE_NIGHT,
    MODE_DEFAULT,
    MODE_IDLE,
    MODE_COUNT
} system_mode_t;

const char *Mode_ToString(system_mode_t mode);

typedef struct
{
    uint16_t threshold_by_mode[MODE_COUNT];
    uint32_t magic;
} system_config_t;

extern system_config_t g_config;

void Config_Init(void);
void Config_Save(void);
void Config_AddAlert(const char *);
#endif
