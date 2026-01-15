# ==================================================================
# stm32_templates_01- STM32Nucleo_F103RB Standard Peripheral Library
# ==================================================================

cmake_minimum_required(VERSION 3.22)
project(stm32_templates_01 LANGUAGES C ASM)

set(APP "Test01")

message(STATUS "Building Application: ${APP}")
set(PROJECT_TARGET "${APP}")

#
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

message(STATUS "项目: ${PROJECT_TARGET}")
message(STATUS "构建类型: ${CMAKE_BUILD_TYPE}")

add_executable(
        ${PROJECT_TARGET}
)

set_target_properties(${PROJECT_TARGET} PROPERTIES
        OUTPUT_NAME $<IF:$<CONFIG:Debug>,${PROJECT_TARGET}_Debug,${PROJECT_TARGET}_Release>
        SUFFIX ".elf"
)


# ==================================================================

# Core_Sources
Set(
        Core_Sources
        Core/sysmem.c
        Core/syscall.c

        Core/startup_stm32f103rbtx.s
        Core/stm32f103rbtx_FLASH.ld
)

# Application_Sources
set(
        Application_Sources
        Application/${APP}/stm32f10x_it.c
        Application/${APP}/main.c
)

# Peripherals_Sources
set(
        Peripherals_Sources
        Peripherals/GPIO/Periph_GPIO.c
        Peripherals/I2C/Periph_I2C.c
        Peripherals/SPI/Periph_SPI.c
)

# Modules_Sources
set(
        Modules_Sources
        Modules/MPU6050/Module_MPU6050.c
        Modules/nRF24L01/Module_nRF24L01.c
        Modules/OLED091/Module_OLED091.c
        Modules/W25Q128/Module_W25Q128.c
)

# Utils_Sources
set(
        Utils_Sources
        Utils/Delay/Util_Delay.c
        Utils/String/Util_String.c
        Utils/Math/Util_Math.c
)

# Libraries_Sources
set(
        Libraries_Sources
        Libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x/system_stm32f10x.c
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



# Core_Include
set(
        Core_Include
        Core
)

# Application_Include
set(
        Application_Include
        Application/${APP}
)

# Peripherals_Include
set(
        Peripherals_Include
        Peripherals/GPIO
        Peripherals/I2C
        Peripherals/SPI
)

# Modules_Include
set(
        Modules_Include
        Modules/MPU6050
        Modules/nRF24L01
        Modules/OLED091
        Modules/W25Q128
)

# Utils_Include
set(
        Utils_Include
        Utils/Delay
        Utils/Math
        Utils/String
)


#Libraries_Include
set(
        Libraries_Include
        Libraries/CMSIS/CM3/CoreSupport
        Libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x
        Libraries/STM32F10x_StdPeriph_Driver/inc
)

# ==================================================================

#
target_sources(

        ${PROJECT_TARGET} PRIVATE
        #
        ${Core_Sources}
        ${Application_Sources}
        ${Modules_Sources}
        ${Utils_Sources}
        #
        ${Libraries_Sources}

)


#
target_include_directories(

        ${PROJECT_TARGET} PRIVATE
        #
        ${Core_Include}
        ${Application_Include}
        ${Modules_Include}
        ${Utils_Include}
        #
        ${Libraries_Include}

)


#
target_link_options(

        ${PROJECT_TARGET} PRIVATE
        #
        -mcpu=cortex-m3
        -mthumb
        -mfloat-abi=soft
        #
        -specs=nosys.specs
        -specs=nano.specs
        #
        -Wl,--gc-sections
        -Wl,--print-memory-usage
        -Wl,-Map=${PROJECT_TARGET}.map
        -Wl,--cref

        -T${CMAKE_CURRENT_SOURCE_DIR}/Core/stm32f103rbtx_FLASH.ld


)

#
target_compile_options(

        ${PROJECT_TARGET} PRIVATE

        #
        -mcpu=cortex-m3
        -mthumb
        -mfloat-abi=soft

        #
        -Wall
        -Wextra

        #
        -fdata-sections
        -ffunction-sections

        #
        -std=gnu11

        #
        -ffreestanding
        -fno-builtin

        # C
        $<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:C>>:-O0 -g3>
        $<$<AND:$<CONFIG:Release>,$<COMPILE_LANGUAGE:C>>:-Os -g0>

        # CPP
        $<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:CXX>>:-O0 -g3>
        $<$<AND:$<CONFIG:Release>,$<COMPILE_LANGUAGE:CXX>>:-Os -g0>

        $<$<COMPILE_LANGUAGE:CXX>: -fno-rtti -fno-exceptions -fno-threadsafe-statics>

        # ASM
        $<$<COMPILE_LANGUAGE:ASM>: -x assembler-with-cpp>
)



target_compile_definitions(${PROJECT_TARGET} PRIVATE
        STM32F10X_MD
        USE_STDPERIPH_DRIVER
        $<$<CONFIG:Debug>:DEBUG>
)


# ==================================================================

# -------------------
# Post Build: 打印详细内存 + 生成 HEX/BIN
# -------------------
add_custom_command(TARGET ${PROJECT_TARGET} POST_BUILD

        COMMAND ${CMAKE_SIZE} -A -x $<TARGET_FILE:${PROJECT_TARGET}>
)
