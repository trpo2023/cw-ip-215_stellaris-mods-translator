#include "parser.hpp"

string TranslatePath(string path)
{
    string buferline = path;
    buferline.replace(buferline.rfind("english.yml"), 11, "russian.yml");

    path.erase(path.rfind("\\"));
    if(path.find("\\english") != string::npos)
    {
        path.replace(path.find("\\english"), 8, "\\russian");
        buferline.replace(buferline.find("\\english"), 8, "\\russian");
    }
    create_directory(path);

    return buferline;
}

void Parser(vector<paths> &Localisations, path mods_path)
{
    for(auto& entry : directory_iterator(mods_path))
    {
        if(is_directory(entry.status())) Parser(Localisations, entry.path());

        if(entry.path().string().find("_l_english.yml") != string::npos)
        {
            paths localisation_paths;
            localisation_paths.original_path = entry.path().string();
            localisation_paths.translate_path = TranslatePath(entry.path().string());
            Localisations.push_back(localisation_paths);
        }
    }
}