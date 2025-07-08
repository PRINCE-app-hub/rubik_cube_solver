cmake_minimum_required(VERSION 3.31)
project(rubik_cube_solver)

set(CMAKE_CXX_STANDARD 20)

add_executable(rubik_cube_solver main.cpp
        model/RubiksCube.h
        model/RubiksCube.cpp
        "model/ RubiksCube1dArray.cpp"
        model/RubiksCube1dArray.h)
