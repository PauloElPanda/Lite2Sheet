find_package(fmt CONFIG REQUIRED)

# Define a small static library for the SQLite wrapper
add_library(sqlite_lib STATIC sqlite.cpp)

# Include headers
target_include_directories(sqlite_lib PUBLIC ${PROJECT_SOURCE_DIR}/inc)

target_link_libraries(sqlite_lib PUBLIC fmt::fmt)