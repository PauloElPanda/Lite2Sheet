#include <sqlite.hpp>

sqlite3* getOrCreateDatabase(const fs::path& dbPath)
{
    sqlite3* db = nullptr;

    // Check if file exists
    bool exists = fs::exists(dbPath);

    // Try to open (or create) database
    int rc = sqlite3_open(dbPath.string().c_str(), &db);
    if (rc != SQLITE_OK)
    {
        fmt::print(stderr, "Failed to open database '{}': {}\n", 
                   dbPath.string(), sqlite3_errmsg(db));
        sqlite3_close(db);
        return nullptr;
    }

    if (!exists)
    {
        fmt::print("Database '{}' created successfully.\n", dbPath.string());

        // Example: initialize with a minimal schema if needed
        const char* createTableSQL = R"(
            CREATE TABLE IF NOT EXISTS example (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                name TEXT
            );
        )";

        char* errMsg = nullptr;
        rc = sqlite3_exec(db, createTableSQL, nullptr, nullptr, &errMsg);
        if (rc != SQLITE_OK)
        {
            fmt::print(stderr, "Failed to initialize new DB: {}\n", errMsg);
            sqlite3_free(errMsg);
        }
        else
        {
            fmt::print("Initialized new database schema.\n");
        }
    }
    else
    {
        fmt::print("Database '{}' opened successfully.\n", dbPath.string());
    }

    return db;
}
