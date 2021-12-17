cmake_minimum_required(VERSION 3.16.3)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(homework VERSION 1.00.0)

add_executable(${PROJECT_NAME} main.cpp core.hpp App.cpp
                            Commands/Commands.cpp
                            Assignments/Assignment.cpp
                            Classes/Class.cpp)
