cmake_minimum_required(VERSION 3.20)

find_package(GTest CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(unofficial-sqlite3 CONFIG REQUIRED)

# Add the test executable
add_executable(Lite2Sheet_tests
    test_config_readers.cpp
)

# Link with the main project libraries
target_link_libraries(Lite2Sheet_tests PRIVATE
    fmt::fmt
    nlohmann_json::nlohmann_json
    unofficial::sqlite3::sqlite3
    Lite2Sheet_Config_lib
)
target_include_directories(Lite2Sheet_tests PRIVATE ${SIMPLEINI_INCLUDE_DIRS})

# Add GoogleTest
find_package(GTest CONFIG REQUIRED)
target_link_libraries(Lite2Sheet_tests PRIVATE GTest::gtest GTest::gtest_main)

# Include headers from your project
target_include_directories(Lite2Sheet_tests PRIVATE
    ${CMAKE_SOURCE_DIR}/inc
    ${CMAKE_SOURCE_DIR}/src
)

# Register the test with CTest
include(GoogleTest)
gtest_discover_tests(Lite2Sheet_tests)