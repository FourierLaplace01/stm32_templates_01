# Peripherals/USART/CMakeLists.txt

#
add_library(Periph_USART OBJECT
        Periph_USART.c
)


#
target_include_directories(Periph_USART PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)


#
target_link_libraries(Periph_USART PUBLIC project_interface)


#
target_link_libraries(${PROJECT_TARGET} PRIVATE Periph_USART)
