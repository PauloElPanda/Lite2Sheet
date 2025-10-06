cmake_minimum_required(VERSION 3.10)

project(Lite2Sheet)

set(CMAKE_CXX_STANDARD 20)

find_package(fmt CONFIG REQUIRED)

add_executable(Lite2Sheet src/main.cpp)

target_link_libraries(Lite2Sheet PRIVATE fmt::fmt)