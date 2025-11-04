
##################
# sqlite_lib
##################

find_package(fmt CONFIG REQUIRED)
find_package(unofficial-sqlite3 CONFIG REQUIRED)

# Define a small static library for the SQLite wrapper
add_library(sqlite_lib STATIC sqlite.cpp)

# Include headers
target_include_directories(sqlite_lib PUBLIC ${PROJECT_SOURCE_DIR}/inc)

target_link_libraries(sqlite_lib PRIVATE unofficial::sqlite3::sqlite3)
target_link_libraries(sqlite_lib PUBLIC fmt::fmt)
