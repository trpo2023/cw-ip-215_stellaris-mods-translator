#include "database.hpp"

DataBase::DataBase(std::string path)
{
    exit = sqlite3_open(path.c_str(), &db);
    std::string sql("CREATE TABLE TRANSLATIONS(ORIGINAL TEXT, TRANSLATION TEXT);");
    exit = sqlite3_exec(db, sql.c_str(), NULL, 0, &errMsg);

    if (exit != SQLITE_OK)
        sqlite3_free(errMsg);
}

DataBase::~DataBase()
{
    sqlite3_close(db);
}

bool found = 0;
int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    found = 1;
    return 0;
}

bool DataBase::check(std::string text)
{
    std::string sql = "SELECT * FROM TRANSLATIONS WHERE ORIGINAL = '" + text + "'";
    exit = sqlite3_exec(db, sql.c_str(), callback, NULL, &errMsg);

    if (exit != SQLITE_OK)
    {
        sqlite3_free(errMsg);
        return 0;
    }

    return found;
}

std::string DataBase::getTranslation(std::string text)
{
    std::string result;
    std::string sql = "SELECT TRANSLATION FROM TRANSLATIONS WHERE ORIGINAL = '" + text + "'";

    exit = sqlite3_exec(
        db, sql.c_str(), [](void *data, int argc, char **argv, char **azColName) -> int
        { *static_cast<std::string *>(data) = argv[0];
        return 0; },
        &result, &errMsg);

    if (exit != SQLITE_OK)
    {
        sqlite3_free(errMsg);
        return "";
    }

    return result;
}

void DataBase::add(std::string text, std::string translation)
{
    std::string sql = "INSERT INTO TRANSLATIONS (ORIGINAL, TRANSLATION) VALUES('" + text + "', '" + translation + "');";
    exit = sqlite3_exec(db, sql.c_str(), NULL, NULL, &errMsg);

    if (exit != SQLITE_OK)
        sqlite3_free(errMsg);
}