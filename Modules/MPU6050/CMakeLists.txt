# Modules/MPU6050/CMakeLists.txt


add_library(
        Module_MPU6050 OBJECT
)


target_sources(Module_MPU6050 PUBLIC
        Module_MPU6050.c
)


target_include_directories(Module_MPU6050 PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)


target_link_libraries(Module_MPU6050 PUBLIC stm32_std_lib)