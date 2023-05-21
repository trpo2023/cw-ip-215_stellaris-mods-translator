#include "parser.hpp"

std::string translatePath(std::string path)
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

void Parser(std::vector<paths> &Localisations, std::filesystem::path modPath)
{
    for(auto& entry : std::filesystem::directory_iterator(modPath))
    {
        if(std::filesystem::is_directory(entry.status()))
            Parser(Localisations, entry.path());

        if(entry.path().string().find("_l_english.yml") != std::string::npos)
        {
            paths localisationPaths;
            localisationPaths.originalPath = entry.path().string();
            localisationPaths.translatePath = translatePath(entry.path().string());
            Localisations.push_back(localisationPaths);
        }
    }
}