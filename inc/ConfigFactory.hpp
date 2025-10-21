#pragma once
#include "IConfigReader.hpp"
#include "JsonConfigReader.hpp"
#include "IniConfigReader.hpp"
#include <memory>
#include <string>

class ConfigFactory {
public:
    static std::unique_ptr<IConfigReader> create(const std::string& filename) 
    {
        if (filename.ends_with(".json"))
            return std::make_unique<JsonConfigReader>();
        else if (filename.ends_with(".ini"))
            return std::make_unique<IniConfigReader>();
        else
            throw std::runtime_error("Unsupported config format: " + filename);
    }
};
