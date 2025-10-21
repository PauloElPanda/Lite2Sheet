#pragma once
#include "IConfigReader.hpp"
#include <nlohmann/json.hpp>
#include <fmt/core.h>
#include <fstream>

class JsonConfigReader : public IConfigReader {
private:
    nlohmann::json data;
public:
    bool load(const std::string& filename) override;
    std::string get(const std::string& section, const std::string& key, const std::string& defaultValue) const override;
    bool save(const std::string& filename) const override;
};
