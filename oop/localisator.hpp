#ifndef H_LOCALISATOR
#define H_LOCALISATOR

#include "mod.hpp"

#include <map>
#include <fstream>
#include <filesystem>
#include <algorithm>

#define FILE_NOT_FOUND 1
#define FILE_TRANSLATED 2
#define FILE_NOT_TRANSLATED 3

class Localisator
{
    std::map<std::string, std::string> files;

    int isTranslated(std::string file);

public:
    Localisator(std::vector<std::string> files);
    std::map<std::string, std::string> getFiles();
    bool createFolders();
    virtual bool localise();
};

#endif