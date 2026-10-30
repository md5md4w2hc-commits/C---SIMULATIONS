cmake_minimum_required(VERSION 3.10)
project(PhysicsSimulation)

set(CMAKE_CXX_STANDARD 17)

find_package(raylib CONFIG REQUIRED)

add_executable(Simulation main.cpp)
target_link_libraries(Simulation PRIVATE raylib)
