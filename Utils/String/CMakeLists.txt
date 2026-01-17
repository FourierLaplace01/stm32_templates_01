# Utils/Math/CMakeLists.txt


#
add_library(Util_String_Object OBJECT
        Util_String.c
)

#
target_include_directories(Util_String_Object PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

#
target_link_libraries(Util_String_Object PUBLIC STM32F10x_Includes_Interface)