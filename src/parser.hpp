#pragma once

#include <filesystem>
#include <vector>

#include "paths.hpp"

std::string translatePath(std::string path);
void Parser(std::vector<paths> &Localisations, std::filesystem::path modsPath);