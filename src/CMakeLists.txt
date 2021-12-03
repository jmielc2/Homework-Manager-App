cmake_minimum_required(VERSION 3.16.3)

project(homework)

add_executable(${PROJECT_NAME} main.cpp core.hpp App.cpp
                            Commands/Commands.cpp
                            Classes/Class.cpp
                            Assignments/Assignment.cpp)
