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
# ==================== MCU 架构 ====================





add_executable(
        ${PROJECT_TARGET}
)


# Other_File
Set(
        Other_File
        Core/sysmem.c
        Core/syscall.c
)

# Config_File
set(
        Config_File
)

# Interrupt_File
set(
        Interrupt_File
        Core/stm32f10x_it.c
)

# Startup_File
set(
        Startup_File
        Core/startup_stm32f103rbtx.s
)

# Linker_File
set(
        Linker_File
        Core/stm32f103rbtx_FLASH.ld
)

# Application_Sources
set(
        Application_Sources
        Application/Src/main.c
)

# Peripherals_Sources
set(
        Peripherals_Sources
        Peripherals/GPIO/gpio.c
        Peripherals/I2C/i2c.c
        Peripherals/SPI/spi.c
)

# Modules
set(
        Modules_Sources
        Modules/MPU6050/MPU6050.c
        Modules/nRF24L01/nRF24L01.c
        Modules/OLED091/OLED091.c
        Modules/W25Q128/W25Q128.c
)

# Utils
set(
        Utils_Sources
        Utils/Delay/utli_delay.c
        Utils/String/util_string.c
        Utils/Math/util_math.c
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
set(
        Include_Directories
        # CMSIS
        Libraries/CMSIS/CM3/CoreSupport
        Libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x

        # StdPeriph
        Libraries/STM32F10x_StdPeriph_Driver/inc

        # Core
        Core

        # Application
        Application/Inc

        # Peripherals
        Peripherals/GPIO
        Peripherals/I2C
        Peripherals/SPI

        # Modules
        Modules/MPU6050
        Modules/nRF24L01
        Modules/OLED091
        Modules/W25Q128

        # Utils
        Utils/Delay
        Utils/Math
        Utils/String
)




# =================================================================
set_target_properties(
        ${PROJECT_TARGET} PROPERTIES
        SUFFIX ".elf"
)


target_sources(

        ${PROJECT_TARGET} PRIVATE
        ${Other_File}
        ${Config_File}
        ${Interrupt_File}
        ${Startup_File}
        ${Linker_File}
        #
        ${Application_Sources}
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
        #
        -mcpu=cortex-m3
        -mthumb
        -mfloat-abi=soft
        #
        -T${CMAKE_CURRENT_SOURCE_DIR}/${Linker_File}
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

        #
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
