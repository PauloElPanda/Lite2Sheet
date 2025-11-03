#pragma once
#include <filesystem>

#include <sqlite3.h>

namespace fs = std::filesystem;

int fillDatabaseWithInput(fs::path& inputPath, fs::path& dbPath);