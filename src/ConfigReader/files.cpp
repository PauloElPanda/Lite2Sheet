#include <filesystem>
#include <files.hpp>

namespace fs = std::filesystem;

int testJson()
{
    try 
    {
        auto config = ConfigFactory::create("config.json");
        if (!config->load("config.json")) 
        {
            fmt::print(stderr, "Failed to load configuration\n");
            return 1;
        }

        std::string inputPath = config->get("input", "path", "input/default.db");
        std::string outputDir = config->get("output", "directory", "output");

        fmt::print("Input Path: {}\n", inputPath);
        fmt::print("Output Dir: {}\n", outputDir);
    } 
    catch (const std::exception& e) 
    {
        fmt::print(stderr, "Error: {}\n", e.what());
        return 1;
    }
}

inline void ensureDirectory(const fs::path& path) {
    fs::path dir(path);
    if (!fs::exists(dir)) 
    {
        fmt::print("Creating directory: {}\n", path.string());
        fs::create_directories(dir);
    } 
    else if (!fs::is_directory(dir)) 
    {
        fmt::print(stderr, "Path exists but is not a directory: {}\n", path.string());
    } 
    else 
    {
        fmt::print("Directory already exists: {}\n", path.string());
    }
}

int filesManagement()
{
    fs::path inputDir = "input";
    fs::path outputDir = "output";

    // Check and create input directory
    ensureDirectory(inputDir);

    // Check and create output directory
    ensureDirectory(outputDir);

    fmt::print("All directories verified.\n");

    
    return 0;
}