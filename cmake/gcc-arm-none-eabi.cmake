# ============================================================
# ARM Cortex-M Toolchain for STM32 (Bare Metal)
# ============================================================

# 告诉 cmake：这是一个裸机系统
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)


# try_compile 不要生成可执行文件
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

# ============================================================
# ARM GCC 路径（按你当前环境）
# ============================================================
set(ARM_GCC_PATH "C:/ST/STM32CubeCLT/GNU-tools-for-STM32/bin")

set(CMAKE_C_COMPILER   ${ARM_GCC_PATH}/arm-none-eabi-gcc.exe)
set(CMAKE_ASM_COMPILER ${ARM_GCC_PATH}/arm-none-eabi-gcc.exe)

set(CMAKE_OBJCOPY ${ARM_GCC_PATH}/arm-none-eabi-objcopy.exe)
set(CMAKE_SIZE    ${ARM_GCC_PATH}/arm-none-eabi-size.exe)

# 可选但推荐
set(CMAKE_AR      ${ARM_GCC_PATH}/arm-none-eabi-ar.exe)
set(CMAKE_RANLIB  ${ARM_GCC_PATH}/arm-none-eabi-ranlib.exe)
