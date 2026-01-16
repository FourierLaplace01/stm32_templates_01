# Utils/Math/CMakeLists.txt


#
add_library(Util_String OBJECT
        Util_String.c
)

#
target_include_directories(Util_String PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

#
target_link_libraries(Util_String PUBLIC project_interface)

#
target_link_libraries(${PROJECT_TARGET} PRIVATE Util_String)
