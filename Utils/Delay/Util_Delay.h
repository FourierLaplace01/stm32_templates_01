#ifndef UTIL_DELAY_H
#define UTIL_DELAY_H

#include <stdint.h>

// 初始化延时模块，必须在 SystemCoreClockUpdate() 后调用
void Util_Delay_Init(void);

// 毫秒延时
void Util_Delay_Ms(uint32_t ms);

// 微秒延时
void Util_Delay_Us(uint32_t us);

#endif
