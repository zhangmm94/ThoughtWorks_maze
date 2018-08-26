cmake_minimum_required(VERSION 2.8)
project(Maze)
add_compile_options(-std=c++11)

include_directories(./include)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
add_library(${PROJECT_NAME} SHARED
    src/maze.cpp
    src/accessgrid.cpp
    )

add_executable(maze main.cpp)
target_link_libraries(maze ${PROJECT_NAME})
