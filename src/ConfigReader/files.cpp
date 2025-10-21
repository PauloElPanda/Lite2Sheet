#include <files.hpp>

int testJsonMng()
{
    try {
        auto config = ConfigFactory::create("config.json");
        if (!config->load("config.json")) {
            fmt::print(stderr, "Failed to load configuration\n");
            return 1;
        }

        std::string inputPath = config->get("input", "path", "input/default.db");
        std::string outputDir = config->get("output", "directory", "output");

        fmt::print("Input Path: {}\n", inputPath);
        fmt::print("Output Dir: {}\n", outputDir);
    } catch (const std::exception& e) {
        fmt::print(stderr, "Error: {}\n", e.what());
        return 1;
    }
}