# Application/Test02/CMakeLists.txt

target_sources(
    ${PROJECT_TARGET} PRIVATE
    main.c
    stm32f10x_it.c
)

target_include_directories(
    ${PROJECT_TARGET} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)