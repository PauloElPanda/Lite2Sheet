#pragma once
// std
#include <fstream>
// ddl
#include <fmt/core.h>
#include <nlohmann/json.hpp>
// local
#include "IConfigReader.hpp"

class JsonConfigReader : public IConfigReader {
private:
    nlohmann::json data;
public:
    bool load(const std::string& filename) override;
    std::string get(const std::string& section, const std::string& key, const std::string& defaultValue) const override;
    bool save(const std::string& filename) const override;
};
