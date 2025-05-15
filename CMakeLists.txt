cmake_minimum_required(VERSION 3.31)
project(LearnOpenGL)

set(CMAKE_CXX_STANDARD 20)

add_executable(LearnOpenGL
        main.cpp
        main.h)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(LearnOpenGL PRIVATE glfw)

find_package(glad CONFIG REQUIRED)
target_link_libraries(LearnOpenGL PRIVATE glad::glad)