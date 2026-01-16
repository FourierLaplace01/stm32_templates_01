# Utils/Log/CMakeLists.txt

#
add_library(Util_Log OBJECT
        Util_Log.c
)

target_include_directories(Util_Log PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

#
target_link_libraries(Util_Log PUBLIC project_interface)


#
target_link_libraries(${PROJECT_TARGET} PRIVATE Util_Log)
