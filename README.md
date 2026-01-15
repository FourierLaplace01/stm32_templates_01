1️⃣ 目标编译选项解释
target_compile_options(
${PROJECT_TARGET} PRIVATE
-mcpu=cortex-m3
-mthumb
-mfloat-abi=soft
)

(1) -mcpu=cortex-m3

指定 目标处理器。

STM32F103 系列使用 Cortex-M3 内核。

作用：

告诉编译器优化指令集。

正确选择寄存器、指令集和内置函数。

如果省略：

GCC 可能使用默认架构（可能是 x86 或 generic ARM），导致 汇编指令不匹配 → 编译失败。

(2) -mthumb

指定使用 Thumb 指令集。

Cortex-M 系列 MCU 通常只支持 Thumb-2 指令。

作用：

编译器生成 16/32 位 Thumb 指令，而不是 ARM 32 位指令。

如果省略：

编译器生成 ARM 指令 → Cortex-M3 不支持 ARM 指令 → 编译失败。

出现错误可能就是 “unknown instruction” 或 “illegal instruction”。

(3) -mfloat-abi=soft

指定 浮点 ABI。

STM32F103 没有 FPU。

作用：

告诉编译器 浮点运算用软件模拟，不要生成 FPU 指令。

如果省略：

GCC 默认可能尝试用硬件 FPU（硬件浮点寄存器） → 编译失败。

错误信息通常带 “VFP not supported” 或 “cannot use FPU registers”。

2️⃣ 为什么注释掉就编译报错？

stm32f10x_pwr.c 中可能包含：

__NOP() 或寄存器操作。

一些条件编译宏依赖 Cortex-M3 架构宏（__CORTEX_M3__）。

如果没有 -mcpu=cortex-m3 -mthumb：

编译器无法识别 Cortex-M3 寄存器和指令。

如果没有 -mfloat-abi=soft：

编译器认为 FPU 可用，尝试生成硬件浮点指令 → STM32F103 编译错误。

所以这三行是 STM32F103 项目必不可少的核心编译选项。

3️⃣ 小结
编译选项	作用	如果省略会怎样
-mcpu=cortex-m3	指定 MCU 架构	寄存器/指令集错误，无法识别 Cortex-M3 特性
-mthumb	使用 Thumb 指令集	生成 ARM 指令，MCU 不支持，报错
-mfloat-abi=soft	软件模拟浮点	MCU 无 FPU → 硬件浮点指令报错

✅ 结论：
这三行不能注释掉，是 STM32F103F MCU 编译的基础选项。