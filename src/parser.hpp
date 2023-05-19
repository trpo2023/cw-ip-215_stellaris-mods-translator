#pragma once

#include <filesystem>
#include <vector>

#include "paths.hpp"

std::string TranslatePath(std::string path);
void Parser(std::vector<paths> &Localisations, fs::path mods_path);