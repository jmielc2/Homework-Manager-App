cmake_minimum_required(VERSION 3.16.3)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(homework VERSION 1.00.0)

add_executable(${PROJECT_NAME} main.cpp App.cpp
                            General/Commands.cpp
                            General/General.cpp
                            Commands/Show.cpp
                            Commands/Add.cpp
                            Commands/Remove.cpp
                            Components/Assignment.cpp)

install(TARGETS homework DESTINATION bin)
