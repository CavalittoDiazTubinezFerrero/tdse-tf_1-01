#include <stdint.h>
#include <string.h>

extern uint16_t mic_offset;
extern uint32_t wcet_mode_update;
extern uint32_t wcet_receive_status;
extern uint32_t wcet_send_status;
extern uint32_t wcet_send_alert;
extern uint32_t wcet_leds_update;

void App_Init(void);
void App_Loop(void);
void App_Loop_Test(void);
void App_UpdateStatusIndicator(void);
