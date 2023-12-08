#ifndef H_LOCALISATOR
#define H_LOCALISATOR

#include "mod.hpp"

#include <map>
#include <fstream>
#include <filesystem>
#include <algorithm>

class Localisator
{
    std::map<std::string, std::string> files;
    int locType;

public:
    void setMod(Mod mod);
    std::map<std::string, std::string> getFiles();
    int getLocType();
    void createFolders();
    virtual int localise();
};

#endif