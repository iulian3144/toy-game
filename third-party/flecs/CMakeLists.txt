cmake_minimum_required(VERSION 3.1)
cmake_policy(SET CMP0063 NEW)

project(flecs LANGUAGES C)

option(FLECS_PIC "Compile static flecs lib with position independent code (PIC)" ON)


add_library(${PROJECT_NAME} STATIC flecs.h flecs.c)
add_library(flecs::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

if(WIN32)
    target_link_libraries(${PROJECT_NAME} wsock32 ws2_32)
endif()
if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_link_libraries(${PROJECT_NAME} pthread)
endif()

if(FLECS_PIC)
    set_property(TARGET ${PROJECT_NAME} PROPERTY POSITION_INDEPENDENT_CODE ON)
endif()

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
