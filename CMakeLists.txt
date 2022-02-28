cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 17)

project(raytracer)

include_directories(
        core
        graphics
        math
)

file(GLOB all_SRCS
        "core/include/*.hh"
        "graphics/include/*.hh"
        "math/include/*.hh"

        "core/*.cc"
        "graphics/*.cc"
        "math/*.cc"

        main.cc
)

add_executable(raytracer ${all_SRCS})