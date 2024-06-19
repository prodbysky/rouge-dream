cmake_minimum_required(VERSION 3.10)
project(Rouge_Dream)

set(CMAKE_CXX_STANDARD 17)

include_directories(include/)

add_executable(game src/main.cpp 
    src/bullet.cpp 
    src/player.cpp 
    src/utils.cpp)

link_directories(lib/)
target_link_libraries(game raylib)
