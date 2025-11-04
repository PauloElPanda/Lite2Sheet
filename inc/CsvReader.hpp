#pragma once
// std
#include <vector>
#include <string>
// local
#include "ISheetReader.hpp"

class CsvReader : public ISheetReader 
{
private:
    vec<vec<str>> data;

public:
    bool read(const fs::path& filePath) override;
    vec<vec<str>> getData() const override { return data; }
};
