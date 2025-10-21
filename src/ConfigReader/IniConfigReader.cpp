#include <IniConfigReader.hpp>

bool IniConfigReader::load(const std::string& filename)
{
    ini.SetUnicode();
    SI_Error rc = ini.LoadFile(filename.c_str());
    if (rc < 0) 
    {
        fmt::print(stderr, "Could not open INI config: {}\n", filename);
        return false;
    }

    fmt::print(stdout, "INI configuration loaded successfully: {}\n", filename);
    return true;
}

std::string IniConfigReader::get(const std::string& section, const std::string& key, const std::string& defaultValue = "") const
{
    const char* value = ini.GetValue(section.c_str(), key.c_str(), defaultValue.c_str());
    if (!value) 
    {
        fmt::print(stderr, "Missing value for [{}]::{} — using default: '{}'\n", section, key, defaultValue);
    }
    return std::string(value ? value : defaultValue.c_str());
}

bool IniConfigReader::save(const std::string& filename) const
{
    SI_Error rc = ini.SaveFile(filename.c_str());
    if (rc < 0) 
    {
        fmt::print(stderr, "Failed to save INI configuration: {}\n", filename);
        return false;
    }

    fmt::print(stdout, "Configuration saved successfully to {}\n", filename);
    return true;
}