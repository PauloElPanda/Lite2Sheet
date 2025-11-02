#include <files.hpp>
#include <sqlite.h>

int main()
{

    void *config = nullptr;

    // Check if directories and the config file exist 
    filesManagement(&config);
    
    // TODO: Get SQLite db, if it doesn't create an empty one
    // TODO: Look for a .xlsx or .csv file as input and fill the db file
    // TODO: Return in output the .xlsx file or .csv corresponding 
    testSqlite();
    return 0;
}
