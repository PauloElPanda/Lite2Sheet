#pragma once
// std
#include <filesystem>
#include <string>
#include <vector>

namespace fs = std::filesystem;
using str = std::string;
template <typename T>
using vec = std::vector<T>;

class ISheetReader 
{
public:
    virtual ~ISheetReader() = default;

    // Read file contents
    virtual bool read(const fs::path& filePath) = 0;

    // Retrieve parsed data as vector of rows (for simplicity)
    virtual vec<vec<str>> getData() const = 0;
};
