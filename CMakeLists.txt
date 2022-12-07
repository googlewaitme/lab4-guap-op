cmake_minimum_required(VERSION 3.23)
project(lab4)

set(CMAKE_CXX_STANDARD 14)


file(GLOB_RECURSE SOURCES
        src/*.h
        src/*.cpp
        src/*.tcc
        src/*.hpp
        )

add_executable(lab4 ${SOURCES})