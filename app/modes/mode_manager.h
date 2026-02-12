#ifndef MODE_MANAGER_H
#define MODE_MANAGER_H

#include "config.h"

void Mode_Init(void);
void Mode_Update(void);
void Mode_UpdateRemote(system_mode_t);
system_mode_t Mode_Get(void);

#endif
