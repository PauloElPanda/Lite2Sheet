
find_package(fmt CONFIG REQUIRED)
find_package(unofficial-sqlite3 CONFIG REQUIRED)

add_library(Lite2Sheet_Import_lib STATIC 
    dataImporter.cpp 
    CsvReader.cpp 
    SheetReaderFactory.cpp
)

target_include_directories(Lite2Sheet_Import_lib PUBLIC ${PROJECT_SOURCE_DIR}/inc)

target_link_libraries(Lite2Sheet_Import_lib PRIVATE unofficial::sqlite3::sqlite3)
target_link_libraries(Lite2Sheet_Import_lib PUBLIC fmt::fmt)