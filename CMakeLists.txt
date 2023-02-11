cmake_minimum_required(VERSION 3.10)
project(game LANGUAGES C)

include(cmake/target_default_compile_options.cmake)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_STANDARD 99)

# Dependencies
## Raylib
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(CMAKE_BUILD_TYPE Debug)
add_subdirectory(third-party/raylib)

## flecs
add_subdirectory(third-party/flecs)
target_default_compile_options_c(flecs)

# Our Project
add_executable(${PROJECT_NAME}
    src/main.c
    src/main_menu.c
    src/game.c)

target_link_libraries(${PROJECT_NAME} raylib flecs)
target_default_compile_options_c(${PROJECT_NAME})
