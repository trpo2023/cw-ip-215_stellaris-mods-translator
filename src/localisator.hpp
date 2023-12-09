#ifndef H_LOCALISATOR
#define H_LOCALISATOR

#include "mod.hpp"

#include <map>
#include <fstream>
#include <filesystem>

class Localisator
{
    std::map<std::string, std::string> files;

public:
    std::map<std::string, std::string> getFiles();
    int addPaths(Mod mod);
    void createFolders();
    virtual int localise(Mod mod);
};

#endif