cmake_minimum_required(VERSION 3.26)
project(calculus_in_cpp)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)
find_package (Eigen3 3.3 REQUIRED NO_MODULE)

add_library(calculus
        differentiation.cpp
        differentiation.h
        Camera.cpp
        Camera.h
        World2D.cpp
        World2D.h
        Object2D.cpp
        Object2D.h
        Hit.cpp
        Hit.h
        Curve2D.cpp
        Curve2D.h
        Canvas2D.cpp
        Canvas2D.h
        transformation.cpp
        transformation.h
)

target_link_libraries(calculus Eigen3::Eigen SDL2::SDL2)

add_executable(derivative_image derivative_image.cpp)
target_link_libraries(derivative_image calculus)
