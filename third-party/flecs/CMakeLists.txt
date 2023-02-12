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
target_compile_options(${PROJECT_NAME} PRIVATE
    $<$<C_COMPILER_ID:MSVC>:
        /w14242 /w14254 /w14263 /w14265 /w14287 /we4289 /w14296 /w14311 /w14545
        /w14546 /w14547 /w14549 /w14555 /w14619 /w14640 /w14826 /w14905 /w14906
        /w14928 /wd4826>)
