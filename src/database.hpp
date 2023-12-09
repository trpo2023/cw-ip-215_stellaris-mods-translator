#ifndef H_DATABASE
#define H_DATABASE

#include <sqlite3.h>
#include <string>

class DataBase
{
    sqlite3 *db;
    int exit;
    char *errMsg = 0;

public:
    DataBase(std::string path);
    ~DataBase();
    
    bool check(std::string text);
    std::string getTranslation(std::string text);
    void add(std::string text, std::string translation);
};

#endif