#include <gtest/gtest.h>
#include <IniConfigReader.hpp>
#include <JsonConfigReader.hpp>

TEST(JsonConfigReaderTest, LoadInvalidFile)
{
    JsonConfigReader reader;
    EXPECT_FALSE(reader.load("nonexistent.json"));
}

TEST(IniConfigReaderTest, LoadInvalidFile)
{
    IniConfigReader reader;
    EXPECT_FALSE(reader.load("missing.ini"));
}
