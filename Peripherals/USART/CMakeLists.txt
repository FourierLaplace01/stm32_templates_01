# Peripherals/USART/CMakeLists.txt

#
add_library(Periph_USART_Object OBJECT
        Periph_USART.c
)


#
target_include_directories(Periph_USART_Object PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)


#
target_link_libraries(Periph_USART_Object PUBLIC STM32F10x_Includes_Interface)


#
#[[
target_link_libraries(${PROJECT_TARGET} PRIVATE Periph_USART)
]]

