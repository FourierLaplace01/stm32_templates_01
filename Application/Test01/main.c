#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_exti.h"
#include "misc.h"
#include <stdio.h>

#include "Util_Delay.h"
#include "Periph_USART.h"

// 引脚定义
#define LED_PIN      GPIO_Pin_5
#define LED_PORT     GPIOA
#define BUTTON_PIN   GPIO_Pin_13
#define BUTTON_PORT  GPIOC

// 全局变量，用于中断计数
volatile uint32_t button_press_count = 0;

// ================= 系统时钟初始化 =================
void SystemClock_Config(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOC |
                           RCC_APB2Periph_AFIO, ENABLE);
}

// ================= GPIO初始化 =================
void GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;

    // LED
    GPIO_InitStruct.GPIO_Pin = LED_PIN;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(LED_PORT, &GPIO_InitStruct);
    GPIO_ResetBits(LED_PORT, LED_PIN);

    // 按钮
    GPIO_InitStruct.GPIO_Pin = BUTTON_PIN;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU; // 上拉输入
    GPIO_Init(BUTTON_PORT, &GPIO_InitStruct);
}

// ================= 外部中断配置 =================
void EXTI_Config(void)
{
    EXTI_InitTypeDef EXTI_InitStruct;
    NVIC_InitTypeDef NVIC_InitStruct;

    GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource13);

    EXTI_InitStruct.EXTI_Line = EXTI_Line13;
    EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Falling;
    EXTI_InitStruct.EXTI_LineCmd = ENABLE;
    EXTI_Init(&EXTI_InitStruct);

    NVIC_InitStruct.NVIC_IRQChannel = EXTI15_10_IRQn;
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStruct);
}

// ================= 主函数 =================
int main(void)
{
    // 系统初始化
    SystemInit();
    SystemCoreClockUpdate();

    SystemClock_Config();
    GPIO_Config();
    EXTI_Config();

    // 初始化延时模块
    Util_Delay_Init();

    // 初始化串口
    Periph_USART_Init();
    printf("System start OK\r\n");

    //
    uint32_t Num = 0;


    while (1)
    {


        // LED 翻转
        GPIO_SetBits(LED_PORT, LED_PIN);
        Util_Delay_Ms(100);

        GPIO_ResetBits(LED_PORT, LED_PIN);
        Util_Delay_Ms(100);

        //
        Periph_USART_Printf("Num = %lu\r\n", Num);
        Periph_USART_Printf("counter: 0x%08X\r\n", Num);
        Periph_USART_Printf("--------------------------------\r\n");
        Num++;
    }
}

// ================= 中断服务函数 =================
void EXTI15_10_IRQHandler(void)
{
    if (EXTI_GetITStatus(EXTI_Line13) != RESET)
    {
        // 更新按键计数
        button_press_count++;

        // 串口打印
        printf("Button pressed! count = %lu\r\n", button_press_count);

        // 清除中断标志
        EXTI_ClearITPendingBit(EXTI_Line13);

        // 简单消抖（可选）
        for (volatile uint32_t i = 0; i < 1000000; i++);
    }
}
