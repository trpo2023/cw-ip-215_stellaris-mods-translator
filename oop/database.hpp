#ifndef H_DATABASE
#define H_DATABASE

#include <string>

class DataBase
{
    std::string path;

public:
    DataBase(std::string path);
    bool check(std::string text);
    std::string getTranslation(std::string text);
    void add(std::string text, std::string translation);
};

#endif