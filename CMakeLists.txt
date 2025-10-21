cmake_minimum_required(VERSION 3.10)
project(Lite2Sheet LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(PROJECT_SOURCE_DIR .)

find_package(fmt CONFIG REQUIRED)

# Add include directory
include_directories(${PROJECT_SOURCE_DIR}/inc)

# Add subdirectory for the libs
add_subdirectory(src/ConfigReader)
add_subdirectory(src/lib)

add_executable(Lite2Sheet src/main.cpp)

target_link_libraries(Lite2Sheet PRIVATE 
    Lite2Sheet_Config_lib
    sqlite_lib
)