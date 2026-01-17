# ==================================================================
# stm32_templates_01 - STM32Nucleo_F103RB Standard Peripheral Library
# ==================================================================

cmake_minimum_required(VERSION 3.28)
project(STM32_Templates_01 LANGUAGES C ASM)

# ==================================================================
# 1. 设置要编译的 Application
# ==================================================================
set(APP "Test01")  # 切换 Test01 / Test02 / Test03 ...
message(STATUS "Building Application: ${APP}")
set(PROJECT_TARGET "${APP}")

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()
message(STATUS "项目目标: ${PROJECT_TARGET}")
message(STATUS "构建类型: ${CMAKE_BUILD_TYPE}")

# ==================================================================
# 2. 创建可执行目标
# ==================================================================
add_executable(${PROJECT_TARGET})

set_target_properties(${PROJECT_TARGET} PROPERTIES
        OUTPUT_NAME $<IF:$<CONFIG:Debug>,${PROJECT_TARGET}_Debug,${PROJECT_TARGET}_Release>
        SUFFIX ".elf"
)

# ==================================================================
# 3. Core sources
# ==================================================================
set(Core_Sources
        Core/sysmem.c
        Core/syscalls.c
        Core/startup_stm32f103rbtx.s
        Core/stm32f103rbtx_FLASH.ld
)

set(Core_Include Core)

# ==================================================================
# 4. Include Application 子目录 CMakeLists.txt
# ==================================================================
add_subdirectory(Application/${APP})


# ==================================================================
# 5. Peripherals sources & includes
# ==================================================================
set(Peripherals_Sources

)
set(Peripherals_Include

)

# ==================================================================
# 6. Modules sources & includes
# ==================================================================
set(Modules_Sources

)
set(Modules_Include

)

# ==================================================================
# 7. Utils sources & includes
# ==================================================================
set(Utils_Sources

)
set(Utils_Include

)

# ==================================================================
# 8. Libraries sources & includes
# ==================================================================
set(Libraries_Sources
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
set(Libraries_Include
        Libraries/CMSIS/CM3/CoreSupport
        Libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x
        Libraries/STM32F10x_StdPeriph_Driver/inc
)

# ==================================================================
# 9. Attach sources and includes to target
# ==================================================================
target_sources(
        ${PROJECT_TARGET} PRIVATE
        ${Core_Sources}
        ${App_Sources}
        ${Peripherals_Sources}
        ${Modules_Sources}
        ${Utils_Sources}
        ${Libraries_Sources}
)

target_include_directories(
        ${PROJECT_TARGET} PRIVATE
        ${Core_Include}
        ${App_Include}        # 来自 Application/TestXX/CMakeLists.txt
        ${Peripherals_Include}
        ${Modules_Include}
        ${Utils_Include}
        ${Libraries_Include}
)

# ==================================================================
# 10. Link options
# ==================================================================
target_link_options(
        ${PROJECT_TARGET} PRIVATE
        #
        -mcpu=cortex-m3
        -mthumb
        -mfloat-abi=soft
        #
        -specs=nosys.specs
        #
        -u _printf_float
        #
        -Wl,--gc-sections
        -Wl,--print-memory-usage
        -Wl,-Map=${PROJECT_TARGET}.map
        -Wl,--cref
        #
        -T${CMAKE_CURRENT_SOURCE_DIR}/Core/stm32f103rbtx_FLASH.ld
)


add_custom_command(TARGET ${PROJECT_TARGET} POST_BUILD
        COMMAND ${CMAKE_SIZE} -A -x $<TARGET_FILE:${PROJECT_TARGET}>
)





# =================================================
add_library(project_interface INTERFACE)

#
target_include_directories(project_interface INTERFACE
        Libraries/CMSIS/CM3/CoreSupport
        Libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x
        Libraries/STM32F10x_StdPeriph_Driver/inc
)



#
target_compile_definitions(project_interface INTERFACE
        STM32F10X_MD
        USE_STDPERIPH_DRIVER
        $<$<CONFIG:Debug>:DEBUG>
)

#
target_compile_options(project_interface INTERFACE
        -mcpu=cortex-m3
        -mthumb
        -mfloat-abi=soft
        #
        -Wall
        -Wextra
        #
        -fdata-sections
        -ffunction-sections
        -ffreestanding
        -fno-builtin
        -std=gnu11
)




# =============================================================


#
add_subdirectory(Utils/Delay)
add_subdirectory(Utils/Log)
add_subdirectory(Utils/Math)
add_subdirectory(Utils/String)
#
add_subdirectory(Peripherals/GPIO)
add_subdirectory(Peripherals/I2C)
add_subdirectory(Peripherals/SPI)
add_subdirectory(Peripherals/USART)
#


target_link_libraries(${PROJECT_TARGET} PRIVATE

        Periph_USART
        #
        Util_Delay
        Util_Log
        Util_Math
        Util_String
)

