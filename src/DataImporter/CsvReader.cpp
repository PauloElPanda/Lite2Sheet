#include "CsvReader.hpp"
#include <fstream>
#include <sstream>
#include <fmt/core.h>

bool CsvReader::read(const fs::path& filePath)
{
    std::ifstream file(filePath);
    if (!file.is_open()) 
    {
        fmt::print(stderr, "Could not open CSV file: {}\n", filePath.string());
        return false;
    }

    fmt::print("Reading CSV: {}\n", filePath.string());
    str line;
    while (std::getline(file, line)) 
    {
        vec<str> row;
        std::stringstream ss(line);
        str cell;

        while (std::getline(ss, cell, ',')) 
        {
            row.push_back(cell);
        }
        data.push_back(row);
    }

    fmt::print("Loaded {} rows from {}\n", data.size(), filePath.string());
    return true;
}
