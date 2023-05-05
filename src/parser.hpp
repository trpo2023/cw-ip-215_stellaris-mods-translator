#pragma once

#include <iostream>
#include <filesystem>
#include <vector>

using namespace std;
using namespace filesystem;

struct paths
{
    string original_path;
    string translate_path;
};

string TranslatePath(string path);
void Parser(vector<paths> &Localisations, path mods_path);