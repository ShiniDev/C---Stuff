cmake_minimum_required(VERSION 3.5)
project(HuntTheWumpus)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -std=c++14 -ggdb")

add_library(
    room
    src/Room.cpp
    src/headers/Room.hpp
    )
add_library(
    gameloop
    src/GameLoop.cpp
    src/headers/GameLoop.hpp
    )

add_executable(
    main
    main.cpp
    )
target_link_libraries(main PUBLIC gameloop)
target_link_libraries(main PUBLIC room)
