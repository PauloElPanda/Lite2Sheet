
find_package(fmt CONFIG REQUIRED)

##################
# sqlite_lib
##################

find_package(unofficial-sqlite3 CONFIG REQUIRED)

# Define a small static library for the SQLite wrapper
add_library(sqlite_lib STATIC sqlite.cpp)

# Include headers
target_include_directories(sqlite_lib PUBLIC ${PROJECT_SOURCE_DIR}/inc)

target_link_libraries(sqlite_lib PRIVATE unofficial::sqlite3::sqlite3)
target_link_libraries(sqlite_lib PUBLIC fmt::fmt)

##################
# files_lib
##################

find_package(nlohmann_json CONFIG REQUIRED)

add_library(files_lib STATIC files.cpp)

# Include header
target_include_directories(files_lib PUBLIC ${PROJECT_SOURCE_DIR}/inc)

target_link_libraries(files_lib PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(files_lib PUBLIC fmt::fmt)