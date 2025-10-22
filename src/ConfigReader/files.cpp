#include <files.hpp>

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

std::unique_ptr<IConfigReader> getConfig(const fs::path& path)
{
    try 
    {
        auto config = ConfigFactory::create(path.string());
        if (!config->load(path.string())) 
        {
            fmt::print(stderr, "Failed to load configuration: {}\n", path.string());
            return nullptr;
        }

        return config;
    } 
    catch (const std::exception& e) 
    {
        fmt::print(stderr, "Error loading configuration: {}\n", e.what());
        return nullptr;
    }
}

int filesManagement()
{
    fs::path inputDir               = "input";
    fs::path outputDir              = "output";
    fs::path configFileName         = "config.json";
    fs::path configDir              = inputDir / configFileName;

    // Check and create input & output directories
    ensureDirectory(inputDir);
    ensureDirectory(outputDir);
    fmt::print("All directories verified.\n");

    auto config = getConfig(configDir);
    if (!config) {
        // TODO: handle error
        return -1;
    }

    return 0;
}