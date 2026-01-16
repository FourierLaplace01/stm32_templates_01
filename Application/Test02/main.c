//
// Created by Win-0201 on 2026/1/15.
//

#include "main.h"
#include "stm32f10x.h"
#include "stm32f10x_gpio.h"

/* 简单的延时函数（阻塞式） */
void Dlay_ms(uint32_t ms)
{
    while (ms--)
    {
        for (uint32_t i = 0; i < 7200; i++)
        {
            __NOP();
        }
    }
}

int main(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    /* 1. 使能 GPIOA 时钟（APB2） */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    /* 2. 配置 PA5 为推挽输出 */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    /* 3. 初始状态：PA5 = 低 */
    GPIO_ResetBits(GPIOA, GPIO_Pin_5);

    /* 4. 主循环：翻转 PA5 */
    while (1)
    {
        GPIO_WriteBit(
            GPIOA,
            GPIO_Pin_5,
            (BitAction)!GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_5)
        );

        Dlay_ms(1000);
    }

}
