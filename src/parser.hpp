#pragma once

#include <filesystem>
#include <vector>

#include "paths.hpp"

using namespace std;
using namespace filesystem;

string TranslatePath(string path);
void Parser(vector<paths> &Localisations, path mods_path);