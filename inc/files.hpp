#pragma once
// std
#include <filesystem>
#include <memory>
// ddl
#include <fmt/std.h>
// local
#include <ConfigFactory.hpp>

namespace fs = std::filesystem;

inline void ensureDirectory(const fs::path& path);
std::unique_ptr<IConfigReader> getConfig(const fs::path& path);

int filesManagement(std::unique_ptr<IConfigReader>& config);
