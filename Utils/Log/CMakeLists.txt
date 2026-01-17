# Utils/Log/CMakeLists.txt

#
add_library(Util_Log_Object OBJECT
        Util_Log.c
)

target_include_directories(Util_Log_Object PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

#
target_link_libraries(Util_Log_Object PUBLIC STM32F10x_Includes_Interface)



