
find_package(nlohmann_json CONFIG REQUIRED)
find_path(SIMPLEINI_INCLUDE_DIRS "ConvertUTF.c")

set(nlohmann-json_IMPLICIT_CONVERSIONS OFF)

add_library(Lite2Sheet_Config_lib STATIC 
    files.cpp
    IniConfigReader.cpp
    JsonConfigReader.cpp
)

target_include_directories(Lite2Sheet_Config_lib PUBLIC ${PROJECT_SOURCE_DIR}/inc)

target_link_libraries(Lite2Sheet_Config_lib PRIVATE nlohmann_json::nlohmann_json)
target_include_directories(Lite2Sheet_Config_lib PRIVATE ${SIMPLEINI_INCLUDE_DIRS})
target_link_libraries(Lite2Sheet_Config_lib PUBLIC fmt::fmt)