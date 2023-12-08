#ifndef H_PARSER
#define H_PARSER

#include "mod.hpp"

#include <fstream>
#include <filesystem>

class Parser
{
    std::string path;

    bool isTranslatable();
    int locType(std::string file);
    void fillFiles(std::vector<std::string> &files, std::filesystem::path path);

public:
    void setPath(std::string path);
    Mod parse();
};

#endif