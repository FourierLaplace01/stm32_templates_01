#include "Util_Delay.h"
#include "stm32f10x.h"

/* ================= 全局毫秒计数器 ================= */
volatile uint32_t Tick_Counter = 0;

/* ================= SysTick 中断函数 ================= */
void SysTick_Handler(void)
{
    Tick_Counter++;
}

/* ================= 延时初始化 ================= */
void Util_Delay_Init(void)
{
    /* SysTick 配置为 1ms 中断 */
    SysTick_Config(SystemCoreClock / 1000);
}

/* ================= 毫秒延时函数 ================= */
void Util_Delay_Ms(const uint32_t Ms)
{
    const uint32_t Start = Tick_Counter;

    while ((Tick_Counter - Start) < Ms)
    {

    }
}
