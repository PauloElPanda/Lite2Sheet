#pragma once
// std
#include <memory>
// ddl
#include <fmt/core.h>
// local
#include "ISheetReader.hpp"
#include "CsvReader.hpp"

class SheetReaderFactory 
{
public:
    static std::unique_ptr<ISheetReader> create(const fs::path& filePath);
};