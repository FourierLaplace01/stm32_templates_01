# Utils/Delay/CMakeLists.txt

#
add_library(Util_Delay_Object OBJECT
        Util_Delay.c
)

#
target_include_directories(Util_Delay_Object PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)


#
target_link_libraries(Util_Delay_Object PUBLIC STM32F10x_Includes_Interface)


#
