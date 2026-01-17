# Utils/Math/CMakeLists.txt


#
add_library(Util_Math_Object OBJECT
        Util_Math.c
)


#
target_include_directories(Util_Math_Object PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)


#
target_link_libraries(Util_Math_Object PUBLIC STM32F10x_Includes_Interface)



