cmake_minimum_required(VERSION 3.10)
project(Lite2Sheet LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(PROJECT_SOURCE_DIR .)

# Enable testing
enable_testing()

# Add include directory
include_directories(${PROJECT_SOURCE_DIR}/inc)

# Add subdirectory for the libs
add_subdirectory(src/ConfigReader)
add_subdirectory(src/DataImporter)
add_subdirectory(src/lib)

# Add tests subdirectory
add_subdirectory(tests)

add_executable(Lite2Sheet src/main.cpp)

target_link_libraries(Lite2Sheet PRIVATE 
    Lite2Sheet_Config_lib
    Lite2Sheet_Import_lib
    sqlite_lib
)