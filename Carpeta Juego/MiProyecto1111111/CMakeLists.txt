cmake_minimum_required(VERSION 3.17)
project(PROYECTOS)

set(CMAKE_CXX_STANDARD 14)

add_executable(DemoSFML  "main.cpp" A4.cpp A4.h)
target_link_libraries(DemoSFML sfml-system sfml-window sfml-graphics sfml-audio)