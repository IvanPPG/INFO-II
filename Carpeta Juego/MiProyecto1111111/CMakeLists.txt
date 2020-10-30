cmake_minimum_required(VERSION 3.17)
project(JUEGO)

set(CMAKE_CXX_STANDARD 14)

find_package(Threads)
add_executable(JUEGO main.cpp A4.cpp P_A.cpp Arreglo.cpp Harrier.cpp Proyectil.cpp Puntuacion.cpp Vida.cpp)
target_link_libraries(JUEGO  sfml-system sfml-window sfml-graphics sfml-audio)