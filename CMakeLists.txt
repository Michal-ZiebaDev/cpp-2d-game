cmake_minimum_required(VERSION 3.16)
project(cpp_2d_game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

add_executable(cpp_2d_game
    src/main.cpp
)

target_link_libraries(cpp_2d_game
    sfml-system
    sfml-window
    sfml-graphics
)
