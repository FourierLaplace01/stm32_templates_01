#include <stdio.h>
#include "stm32f10x.h"
#include "Util_Delay.h"
#include "Periph_USART.h"


/* =================================================== */

int main(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    /* 系统初始化 */
    SystemInit();
    SystemCoreClockUpdate();

    /* 延时模块初始化 */
    Util_Delay_Init();

    /* LED PA5 初始化 */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIO_ResetBits(GPIOA, GPIO_Pin_5);

    /* 串口初始化（Nucleo-F103RB -> USART2 / ST-LINK VCP） */
    Periph_USART_Init();
    printf("System start OK\r\n");
    uint32_t Num = 0;

    while (1)
    {
        Num++;

        GPIO_SetBits(GPIOA, GPIO_Pin_5);
        Util_Delay_Ms(1000);
        GPIO_ResetBits(GPIOA, GPIO_Pin_5);
        Util_Delay_Ms(1000);

        Periph_USART_Printf("Num = %lu\r\n", Num);
        Periph_USART_Printf("counter: 0x%08X\r\n", Num);
        Periph_USART_Printf("--------------------------------\r\n");



    }
}
