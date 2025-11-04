#pragma once
// std
#include <filesystem>
// ddl
#include <fmt/core.h>
#include <sqlite3.h>

namespace fs = std::filesystem;

sqlite3* getOrCreateDatabase(const fs::path& dbPath);

