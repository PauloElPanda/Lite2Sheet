#pragma once
// ddl
#include <fmt/core.h>
#include <SimpleIni.h>
// local
#include "IConfigReader.hpp"

class IniConfigReader : public IConfigReader 
{
private:
    CSimpleIniA ini;

public:
    bool load(const std::string& filename) override;
    std::string get(const std::string& section, const std::string& key, const std::string& defaultValue) const override;
    bool save(const std::string& filename) const override;
};
