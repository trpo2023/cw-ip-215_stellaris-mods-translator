#include "parser.hpp"

std::string TranslatePath(std::string path)
{
    std::string buferline = path;
    buferline.replace(buferline.rfind("english.yml"), 11, "russian.yml");

    path.erase(path.rfind("\\"));
    if(path.find("\\english") != std::string::npos)
    {
        path.replace(path.find("\\english"), 8, "\\russian");
        buferline.replace(buferline.find("\\english"), 8, "\\russian");
    }
    std::filesystem::create_directory(path);

    return buferline;
}

void Parser(std::vector<paths> &Localisations, std::filesystem::path mods_path)
{
    for(auto& entry : std::filesystem::directory_iterator(mods_path))
    {
        if(std::filesystem::is_directory(entry.status())) Parser(Localisations, entry.path());

        if(entry.path().string().find("_l_english.yml") != std::string::npos)
        {
            paths localisation_paths;
            localisation_paths.original_path = entry.path().string();
            localisation_paths.translate_path = TranslatePath(entry.path().string());
            Localisations.push_back(localisation_paths);
        }
    }
}