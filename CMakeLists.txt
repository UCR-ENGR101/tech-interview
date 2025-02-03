cmake_minimum_required(VERSION 3.10)

project(tech_interview)

add_executable(reverse src/main.cpp)
target_include_directories(reverse PUBLIC include)
