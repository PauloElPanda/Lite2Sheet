#include <files.h>

int testJsonMng()
{
    std::fstream configFile("config.json");
    if (!configFile) {
        fmt::print(stderr, "⚠️  Could not open config.json");
        return 1;
    }

    json config;
    configFile >> config;

    std::string inputPath = config["input"]["path"];
    std::string outputDir = config["output"]["directory"];
    std::string format = config["output"]["format"];

    fmt::print(stdout, "Input Path: {}\n", inputPath);
    fmt::print(stdout, "Output Dir: {}\n", outputDir);
    fmt::print(stdout, "Format: {}\n", format);
    return 0;
}