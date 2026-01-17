# ==================================================================
# stm32_templates_01- STM32Nucleo_F103RB Standard Peripheral Library
# ==================================================================

cmake_minimum_required(VERSION 3.22)
project(stm32_templates_01 LANGUAGES C ASM)

# ==================================================================



Set(
        Core_Sources
        #
        Core/startup_stm32f103rbtx.s
        Core/stm32f103rbtx_FLASH.ld
        Core/sysmem.c
        Core/syscalls.c
)


# Core_Include
set(
        Core_Include
        #
        Core
)


# Libraries_Sources
set(
        Libraries_Sources
        #
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



#Libraries_Include
set(
        Libraries_Include
        #
        Libraries/CMSIS/CM3/CoreSupport
        Libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x
        Libraries/STM32F10x_StdPeriph_Driver/inc
)


# ==================================================================


add_library(
            STM32F10x_Includes_Interface INTERFACE
)

target_include_directories(

        STM32F10x_Includes_Interface INTERFACE
        #
        ${Core_Include}
        ${Libraries_Include}

)


#========================================================


add_library(

        STM32F10x_Sources_Object OBJECT
)


target_sources(

        STM32F10x_Sources_Object PRIVATE
        ${Core_Sources}
        ${Libraries_Sources}

)


target_link_libraries(
        STM32F10x_Sources_Object PUBLIC
        STM32F10x_Includes_Interface
)



#========================================================
add_subdirectory(Application/Test01)
add_subdirectory(Application/Test02)


# Core_Sources
#========================================================

#
add_subdirectory(Utils/Delay)

#
add_subdirectory(Utils/Log)

#
add_subdirectory(Utils/Math)

#
add_subdirectory(Utils/String)

#
add_subdirectory(Peripherals/USART)

#
add_subdirectory(Peripherals/UserButton)


# ===================================================================


