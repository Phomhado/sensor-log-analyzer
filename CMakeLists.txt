cmake_minimum_required(VERSION 3.16)

project(SensorLogAnalyzer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
    SensorLogAnalyzer
    src/main.cpp
)