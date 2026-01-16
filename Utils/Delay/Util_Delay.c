#include "Util_Delay.h"
#include "stm32f10x.h"

// SysTick 毫秒计数
static volatile uint32_t uwTick = 0;

// SysTick 中断处理
void SysTick_Handler(void)
{
    uwTick++;
}

// 初始化 SysTick，每 1ms 触发一次中断
void Util_Delay_Init(void)
{
    // 确保 SystemCoreClock 已经更新
    // 每 1ms 触发一次
    SysTick_Config(SystemCoreClock / 1000);
}

// 毫秒延时
void Util_Delay_Ms(uint32_t ms)
{
    uint32_t start = uwTick;
    while ((uwTick - start) < ms)
    {
        __NOP();
    }
}

// 简单微秒延时（不依赖 SysTick，中等精度）
void Util_Delay_Us(uint32_t us)
{
    // 假设 CPU 72MHz
    uint32_t count = us * (SystemCoreClock / 1000000UL / 5); // 5 是循环调校值
    while (count--)
    {
        __NOP();
    }
}
