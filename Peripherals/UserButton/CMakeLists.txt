# 定义模块对象
add_library(Periph_UserButton_Object OBJECT
        Periph_UserButton.c
)

# 包含目录
target_include_directories(Periph_UserButton_Object PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

# 链接串口模块
target_link_libraries(Periph_UserButton_Object PRIVATE
        Periph_USART_Object
)
