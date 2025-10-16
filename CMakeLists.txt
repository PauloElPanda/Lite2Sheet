cmake_minimum_required(VERSION 3.10)
project(Lite2Sheet LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(PROJECT_SOURCE_DIR .)

find_package(unofficial-sqlite3 CONFIG REQUIRED)

# Add include directory
include_directories(${PROJECT_SOURCE_DIR}/inc)

# Add subdirectory for the libs
add_subdirectory(src/lib)

add_executable(Lite2Sheet src/main.cpp)

target_link_libraries(Lite2Sheet PRIVATE 
    sqlite_lib 
    unofficial::sqlite3::sqlite3
)