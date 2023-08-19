cmake_minimum_required(VERSION 3.26)
project(VerletRope)

set(CMAKE_CXX_STANDARD 23)

add_executable(VerletRope main.cpp
        Particle.cpp
        Particle.h
        Stick.cpp
        Stick.h)

target_link_libraries(VerletRope sfml-graphics sfml-window sfml-system)
