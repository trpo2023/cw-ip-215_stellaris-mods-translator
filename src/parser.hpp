#ifndef H_PARSER
#define H_PARSER

#include "mod.hpp"

#include <fstream>
#include <filesystem>

class Parser
{
    bool isTranslatable(std::string path);
    int locType(std::string file);
    void fillFiles(std::vector<std::string> &files, std::filesystem::path path);

public:
    Mod parse(std::string path);
};

#endif