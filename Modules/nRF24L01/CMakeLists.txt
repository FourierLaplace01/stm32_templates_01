add_library(
    Module_nRF24L01 STATIC
    Module_nRF24L01.c
)

target_include_directories(
    Module_nRF24L01 PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}"
)
