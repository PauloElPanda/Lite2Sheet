#pragma once
#include <string>
#include <unordered_map>

class IConfigReader {
public:
    virtual ~IConfigReader() = default;

    // Load configuration from file
    virtual bool load(const std::string& filename) = 0;

    // Retrieve a value as string (returns defaultValue if not found)
    virtual std::string get(const std::string& section, const std::string& key, const std::string& defaultValue = "") const = 0;

    // Save modifications back to file
    virtual bool save(const std::string& filename) const = 0;
};
