#include "SheetReaderFactory.hpp"

std::unique_ptr<ISheetReader> SheetReaderFactory::create(const fs::path& filePath)
{
    auto ext = filePath.extension().string();

    if (ext == ".csv" || ext == ".CSV") 
    {
        return std::make_unique<CsvReader>();
    }

    // TODO: Read .xlsx files

    fmt::print(stderr, "Unsupported file format for: {}\n", filePath.filename().string());
    return nullptr;
}