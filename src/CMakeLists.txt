cmake_minimum_required(VERSION 3.16.3)

project(Homework-App)

add_executable(${PROJECT_NAME} main.cpp core.hpp App.cpp
                            States/MainMenu.cpp States/State.cpp
                            Classes/Class.cpp
                            Assignments/Assignment.cpp
                            Trackers/Tracker.cpp Trackers/AssignmentTracker.cpp Trackers/ClassTracker.cpp)
