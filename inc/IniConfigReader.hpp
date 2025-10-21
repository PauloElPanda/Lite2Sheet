#pragma once
#include "IConfigReader.hpp"
#include <SimpleIni.h>
#include <fmt/core.h>

class IniConfigReader : public IConfigReader {
private:
    CSimpleIniA ini;

public:
    bool load(const std::string& filename) override;
    std::string get(const std::string& section, const std::string& key, const std::string& defaultValue) const override;
    bool save(const std::string& filename) const override;
};
