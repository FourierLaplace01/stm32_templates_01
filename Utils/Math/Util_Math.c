#include "Util_Math.h"

// 这里随便引用一个 STM32 标准库头文件，模拟依赖标准库
#include "stm32f10x_rcc.h"

uint32_t Util_Math_GetNum(uint32_t num)
{
    // 调用标准库的宏或寄存器访问，保证模块编译时依赖标准库
    volatile uint32_t dummy = RCC->CR;  // 读取 RCC_CR 寄存器示例
    (void)dummy;

    return num;  // 返回输入数值，供延时循环使用
}
