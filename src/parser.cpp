#include "parser.hpp"

string TranslatePath(string path)
{
    if(path.find("\\english") != string::npos)
        path.replace(path.find("\\english"), 8, "\\russian");

    return path.erase(path.rfind("\\"));
}

void Parser(vector<paths> &Localisations, path mods_path)
{
    for(auto& entry : directory_iterator(mods_path))
    {
        if(is_directory(entry.status())) Parser(Localisations, entry.path());

        else if(entry.path().string().find("_l_english.yml") != string::npos)
        {
            paths localisation_paths;
            localisation_paths.original_path = entry.path().string();
            localisation_paths.translate_path = TranslatePath(entry.path().string());
            Localisations.push_back(localisation_paths);
        }
    }
}