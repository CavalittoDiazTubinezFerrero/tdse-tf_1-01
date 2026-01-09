#ifndef MODE_MANAGER_H
#define MODE_MANAGER_H

typedef enum {
	MODE_DEFAULT = 0,
	MODE_DAY,
	MODE_NIGHT
} system_mode_t;

void Mode_Init(void);
void Mode_Update(void);
system_mode_t Mode_Get(void);

#endif
