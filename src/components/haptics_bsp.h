#ifndef HAPTICS_BSP_H
#define HAPTICS_BSP_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

bool haptics_bsp_init(void);
void haptics_bsp_play_standard_tick(void);
void haptics_bsp_play_limit_tick(void);

#ifdef __cplusplus
}
#endif

#endif
