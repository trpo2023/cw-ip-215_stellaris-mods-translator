#ifndef H_PARSER
#define H_PARSER

#include "mod.hpp"

#include <fstream>
#include <filesystem>

class Parser
{
    std::string path;

    bool isTranslatable();
    void fillFiles(std::vector<std::string> &files, std::filesystem::path path);

public:
    Parser(std::string path);
    Mod parse();
};

#endif