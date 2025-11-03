#include <configReader.hpp>
#include <sqlite.hpp>

int main()
{

    std::unique_ptr<IConfigReader> config;

    // Check if directories and the config file exist 
    filesManagement(config);
    fs::path inputPath = config->get("paths", "input_path");
    fs::path outputPath = config->get("paths", "output_path");
    fs::path dbfilename = config->get("filenames", "db_name");
    
    // Get SQLite db, if it doesn't create an empty one
    fs::path dbPath = inputPath / dbfilename;
    sqlite3* db = getOrCreateDatabase(dbPath);


    // TODO: Look for a .xlsx or .csv file as input and fill the db file
    // TODO: Return in output the .xlsx file or .csv corresponding

    return 0;
}
