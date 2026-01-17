# ============================================================
# ARM Cortex-M Toolchain for STM32 (Bare Metal)
# ============================================================

#
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)


#
set(TOOLCHAIN_PREFIX                arm-none-eabi-)
set(CMAKE_C_COMPILER                ${TOOLCHAIN_PREFIX}gcc)
set(CMAKE_ASM_COMPILER              ${CMAKE_C_COMPILER})
set(CMAKE_CXX_COMPILER              ${TOOLCHAIN_PREFIX}g++)
set(CMAKE_LINKER                    ${TOOLCHAIN_PREFIX}g++)
set(CMAKE_OBJCOPY                   ${TOOLCHAIN_PREFIX}objcopy)
set(CMAKE_SIZE                      ${TOOLCHAIN_PREFIX}size)



# ========================================
# STM32F103 Toolchain - MX 风格集中管理
# ========================================

# 系统/处理器
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

# 工具链前缀
set(TOOLCHAIN_PREFIX arm-none-eabi-)

# 编译器 / 链接器 / 工具
set(CMAKE_C_COMPILER   ${TOOLCHAIN_PREFIX}gcc)
set(CMAKE_CXX_COMPILER ${TOOLCHAIN_PREFIX}g++)
set(CMAKE_ASM_COMPILER ${CMAKE_C_COMPILER})
set(CMAKE_LINKER       ${TOOLCHAIN_PREFIX}g++)
set(CMAKE_OBJCOPY      ${TOOLCHAIN_PREFIX}objcopy)
set(CMAKE_SIZE         ${TOOLCHAIN_PREFIX}size)

# 可执行文件后缀
set(CMAKE_EXECUTABLE_SUFFIX ".elf")

# ============================
# MCU / CPU / Thumb / ABI
# ============================
set(MCU_FLAGS "-mcpu=cortex-m3 -mthumb -mfloat-abi=soft")

# ============================
# 全局编译选项
# ============================
set(CMAKE_C_FLAGS "${MCU_FLAGS} -Wall -Wextra -fdata-sections -ffunction-sections -std=gnu11 -ffreestanding -fno-builtin")
set(CMAKE_CXX_FLAGS "${MCU_FLAGS} -Wall -Wextra -fdata-sections -ffunction-sections -std=gnu++11 -ffreestanding -fno-builtin -fno-rtti -fno-exceptions -fno-threadsafe-statics")
set(CMAKE_ASM_FLAGS "${MCU_FLAGS} -x assembler-with-cpp -MMD -MP")

# ============================
# Debug / Release
# ============================
set(CMAKE_C_FLAGS_DEBUG   "-O0 -g3")
set(CMAKE_C_FLAGS_RELEASE "-Os -g0")
set(CMAKE_CXX_FLAGS_DEBUG   "-O0 -g3")
set(CMAKE_CXX_FLAGS_RELEASE "-Os -g0")

# ============================
# 链接器选项
# ============================
set(CMAKE_EXE_LINKER_FLAGS "${MCU_FLAGS} -T ${CMAKE_CURRENT_SOURCE_DIR}/Core/stm32f103rbtx_FLASH.ld -specs=nosys.specs -Wl,--gc-sections -Wl,--print-memory-usage -Wl,-Map=${CMAKE_PROJECT_NAME}.map -Wl,--cref")

# ============================
# 默认链接库
# ============================
set(TOOLCHAIN_LINK_LIBRARIES "m")





# 工具链文件里写全局宏
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER")

# Debug 模式下额外宏
set(CMAKE_C_FLAGS_DEBUG   "${CMAKE_C_FLAGS_DEBUG} -DDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")

