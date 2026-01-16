#ifndef PERIPH_USART_H
#define PERIPH_USART_H

#ifdef __cplusplus
extern "C" {
#endif

    // 包含必要的头文件
#include <stdint.h>

    /* 函数声明 */

    // 串口初始化
    void Periph_USART_Init(void);

    // 发送单个字符
    void Periph_USART_SendChar(char ch);

    // 发送字符串
    void Periph_USART_SendStr(const char *str);

    // 包装的printf函数（可变参数函数声明）
    int Periph_USART_Printf(const char *format, ...);

#ifdef __cplusplus
}
#endif

#endif /* PERIPH_USART_H */