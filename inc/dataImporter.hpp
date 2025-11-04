#pragma once
// std
#include <filesystem>
// ddl
#include <sqlite3.h>
// local
#include "SheetReaderFactory.hpp"

namespace fs = std::filesystem;

int fillDatabaseWithInput(fs::path& inputPath, fs::path& dbPath);