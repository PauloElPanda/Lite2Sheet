#include <sqlite.h>

int testSqlite()
{
    sqlite3* DB;
    int exit = 0;
    exit = sqlite3_open("example.db", &DB);

    if (exit) {
        fmt::print(stderr, "Error open DB: {}\n", sqlite3_errmsg(DB));
        return (-1);
    }
    else
        fmt::print(stdout, "Opened Database Successfully!");
    sqlite3_close(DB);
    return 0;
}