# ============================================================
# stm32_templates_01- STM32Nucleo_F103RB Standard Peripheral Library
# ============================================================

cmake_minimum_required(VERSION 3.22)
project(stm32_templates_01 LANGUAGES C ASM)
set(PROJECT_TARGET stm32_templates_01)

# ==================== 构建类型 ====================
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "" FORCE)
endif ()

message(STATUS "项目: ${PROJECT_TARGET}")
message(STATUS "芯片: STM32Nucleo_F103RB (Cortex-M3)")
message(STATUS "构建类型: ${CMAKE_BUILD_TYPE}")

add_executable(${PROJECT_TARGET}
        Application/Src/app.test.c
        Application/Inc/app.test.h)

# Cnfig
set(
        Config_File

)
# Interrupt
set(
        Interrupt_Sources
        Interrupt/stm32f10x_it.c
)

# Startup
set(
        Startup_File
        Startup/startup_stm32f103rbtx.s
)

# Linker
set(
        Linker_File
        ${CMAKE_CURRENT_SOURCE_DIR}/Linker/stm32f103rbtx_FLASH.ld
)

# Application
set(Application_Sources
        Application/Src/app_main.c
)

# Peripherals
set(
        Peripherals_Sources
        Peripherals/src/gpio.c
        Peripherals/src/i2c.c
        Peripherals/src/spi.c
)

# Modules
set(
        Modules_Sources
        Modules/MPU6050/Src/MPU6050.c
        Modules/nRF24L01/Src/nRF24L01.c
        Modules/OLED091/Src/OLED091.c
        Modules/W25Q128/Src/W25Q128.c
)

# Utils
set(
        #
        Utils_Sources
        Utils/Src/sysmem.c
        Utils/Src/syscalls.c
        #
        Utils/Src/utli_delay.c
        Utils/Src/util_string.c
        Utils/Src/util_math.c
        Utils/Src/utli_log.c
)

# CMSIS
set(
        CMSIS_Sources
        Libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x/system_stm32f10x.c
)

# StdPeriph
set(
        StdPeriph_Sources
        Libraries/STM32F10x_StdPeriph_Driver/src/misc.c
        Libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_adc.c
        Libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_bkp.c
        Libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_can.c
        Libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_cec.c
        Libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_crc.c
        Libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_dac.c
        Libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_dbgmcu.c
        Libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_dma.c
        Libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_exti.c
        Libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_flash.c
        Libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_fsmc.c
        Libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_gpio.c
        Libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_i2c.c
        Libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_iwdg.c
        Libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_pwr.c
        Libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_rcc.c
        Libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_rtc.c
        Libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_sdio.c
        Libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_spi.c
        Libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_tim.c
        Libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_usart.c
        Libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_wwdg.c
)

# Include_Directories
set(Include_Directories
        # CMSIS
        Libraries/CMSIS/CM3/CoreSupport
        Libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x

        # StdPeriph
        Libraries/STM32F10x_StdPeriph_Driver/inc

        # Config
        Config

        # Interrupt
        Interrupt

        # Startup
        Startup

        # Application
        Application/Inc

        # Peripherals
        Peripherals/Inc

        # Modules
        Modules/MPU6050/Inc
        Modules/nRF24L01/Inc
        Modules/OLED091/Inc
        Modules/W25Q128/Inc

        # Utils
        Utils/Inc
)

set_target_properties(
        ${PROJECT_TARGET} PROPERTIES
        SUFFIX ".elf"
)


target_sources(

        ${PROJECT_TARGET} PRIVATE
        #
        ${Config_File}
        ${Interrupt_Sources}
        ${Startup_File}
        ${Linker_File}
        #
        ${Application_Sources}
        ${Peripherals_Sources}
        ${Modules_Sources}
        ${Utils_Sources}
        #
        ${CMSIS_Sources}
        ${StdPeriph_Sources}


)

target_include_directories(

        ${PROJECT_TARGET} PRIVATE
        ${Include_Directories}
)



target_link_options(
        ${PROJECT_TARGET} PRIVATE
        ${MCU_ARCH_OPTIONS}
        -T${Linker_File}
        -specs=nosys.specs
        -specs=nano.specs
        -Wl,--gc-sections
        -Wl,-Map=${PROJECT_TARGET}.map
)

target_compile_options(
        ${PROJECT_TARGET} PRIVATE
        #
        -mcpu=cortex-m3
        -mthumb
        -mfloat-abi=soft

        #yi
        -Wall -Wextra
        -ffreestanding
        -fno-builtin
        -fdata-sections
        -ffunction-sections
        -std=gnu11
        $<$<CONFIG:Debug>:-Og -g3>
        $<$<CONFIG:Release>:-O3>
        $<$<COMPILE_LANGUAGE:ASM>:-x assembler-with-cpp>
)

target_compile_definitions(${PROJECT_TARGET} PRIVATE
        STM32F103xB
        STM32F10X_MD
        USE_STDPERIPH_DRIVER
        $<$<CONFIG:Debug>:DEBUG>
)


add_custom_command(
        TARGET ${PROJECT_TARGET} POST_BUILD
        COMMAND ${CMAKE_SIZE} $<TARGET_FILE:${PROJECT_TARGET}>
        COMMAND ${CMAKE_OBJCOPY} -O ihex $<TARGET_FILE:${PROJECT_TARGET}> ${PROJECT_TARGET}.hex
        COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${PROJECT_TARGET}> ${PROJECT_TARGET}.bin
)

message(STATUS "========================================")
message(STATUS "输出: ${PROJECT_TARGET}.elf / .hex / .bin")
message(STATUS "========================================")
