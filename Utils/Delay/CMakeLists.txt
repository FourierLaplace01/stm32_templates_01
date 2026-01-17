# Utils/Delay/CMakeLists.txt

#
add_library(Util_Delay OBJECT
        Util_Delay.c
)

#
target_include_directories(Util_Delay PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)


#
target_link_libraries(Util_Delay PUBLIC project_interface)


#
