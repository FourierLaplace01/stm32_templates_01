#ifndef __UTIL_DELAY_H
#define __UTIL_DELAY_H

#include <stdint.h>

/* 初始化 SysTick 为 1ms */
void Util_Delay_Init(void);

/* 毫秒延时 */
void Util_Delay_Ms(uint32_t Ms);

#endif
