#include <configReader.hpp>

inline void ensureDirectory(const fs::path& path) 
{
    /*
    *   Ensure that the directory exist
    */
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
            // TODO?: Config .json / .ini should follow a template ?
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

int filesManagement(std::unique_ptr<IConfigReader>& config)
{
    /*
    *  Ensure that the directories 'input' & 'output' exist
    *  Ensure that a 'config' file exist  
    */ 
    fs::path configDir = fs::path("input") / "config.json";
    config = getConfig(configDir);
    if (!config) 
    {
        // TODO: Handle error
        return -1;
    }

    // Check and create input & output directories
    ensureDirectory(config->get("paths", "input_path"));
    ensureDirectory(config->get("paths", "output_path"));
    fmt::print("All directories verified.\n");

    return 0;
}