cmake_minimum_required (VERSION 3.2)

project(oop_exercise_03)

add_executable(oop_exercise_03 main.cpp point.cpp figure.cpp triangle.cpp square.cpp rectangle.cpp vector.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set_target_properties(oop_exercise_03 PROPERTIES CXX_STANDART 14 CXX_STANDART_REQUIRED ON)