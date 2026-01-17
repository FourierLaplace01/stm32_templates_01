# Application/Test01/CMakeLists.txt


# ==================================================================
set(Application_Target_Name "Test01")

#
add_executable(
        ${Application_Target_Name}
)


set_target_properties(${Application_Target_Name} PROPERTIES
        OUTPUT_NAME_DEBUG   ${Application_Target_Name}_Debug
        OUTPUT_NAME_RELEASE ${Application_Target_Name}_Release
        SUFFIX ".elf"
)


# ==================================================================
target_sources(

        ${Application_Target_Name} PRIVATE
        main.c

)


#
target_include_directories(
        ${Application_Target_Name} PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}

)


#
target_link_libraries(

        ${Application_Target_Name} PUBLIC
        STM32F10x_Sources_Object

)


#
target_link_libraries(

        ${Application_Target_Name} PRIVATE
        Util_Delay_Object
        Util_Log_Object
        Util_String_Object
        Util_Math_Object
        Periph_USART_Object
        Periph_UserButton_Object
)



# ==================================================================
add_custom_command(TARGET ${Application_Target_Name} POST_BUILD

        COMMAND ${CMAKE_SIZE} -A -x $<TARGET_FILE:${Application_Target_Name}>
)
