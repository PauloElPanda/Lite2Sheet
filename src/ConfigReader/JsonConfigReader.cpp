#include <JsonConfigReader.hpp>

bool JsonConfigReader::load(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file.is_open()) 
    {
        fmt::print(stderr, "Could not open JSON config: {}\n", filename);
        return false;
    }
    try {
        file >> data;
    } catch (const std::exception& e) {
        fmt::print(stderr, "JSON parse error: {}\n", e.what());
        return false;
    }
    return true;
}

std::string JsonConfigReader::get(const std::string& section, const std::string& key, const std::string& defaultValue = "") const
{
    try {
        if (data.contains(section) && data[section].contains(key))
            return data[section][key].get<std::string>();
    } catch (...) {
        fmt::print(stderr, "Failed to retrieve key '{}.{}' — using default value.\n", section, key);
    }
    return defaultValue;
}

bool JsonConfigReader::save(const std::string& filename) const
{
    std::ofstream file(filename);
    if (!file.is_open()) {
        fmt::print(stderr, "Could not open file for writing: {}\n", filename);
        return false;
    }
    try {
        file << data.dump(4);
        fmt::print("Configuration saved successfully to {}\n", filename);
    } catch (const std::exception& e) {
        fmt::print(stderr, "Failed to save JSON config: {}\n", e.what());
        return false;
    }
    return true;
}
