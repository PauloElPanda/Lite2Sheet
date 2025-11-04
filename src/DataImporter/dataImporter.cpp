#include <dataImporter.hpp>

int fillDatabaseWithInput(fs::path& inputPath, fs::path& dbPath)
{
    // TODO: Write database with provided data

    fmt::print("Scanning input directory: {}\n", inputPath.string());

    if (!fs::exists(inputPath) || !fs::is_directory(inputPath)) 
    {
        fmt::print(stderr, "Input path '{}' is not a valid directory\n", inputPath.string());
        return 1;
    }

    // Check every files in "inputPath" directory
    for (const auto& entry : fs::directory_iterator(inputPath)) 
    {
        if (!entry.is_regular_file()) continue;

        auto filePath = entry.path();
        auto reader = SheetReaderFactory::create(filePath);
        if (!reader) continue; // skip unsupported formats

        if (reader->read(filePath)) 
        {
            auto data = reader->getData();

            fmt::print("Will insert {} rows from {}\n", data.size(), filePath.filename().string());
        }
    }

    return 0;
}