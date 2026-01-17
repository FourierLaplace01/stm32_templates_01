# Utils/Math/CMakeLists.txt


#
add_library(Util_Math OBJECT
        Util_Math.c
)


#
target_include_directories(Util_Math PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)


#
target_link_libraries(Util_Math PUBLIC project_interface)



