#pragma once

#include <filesystem>
#include <vector>

#include "paths.hpp"

std::string TranslatePath(std::string path);
void Parser(std::vector<paths> &Localisations, std::filesystem::path mods_path);