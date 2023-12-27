#include "localisator.hpp"

std::map<std::string, std::string> Localisator::getFiles()
{
    return files;
}

void Localisator::addPaths(Mod mod)
{
    for (auto &file : mod.getFiles())
        this->files.insert(std::pair<std::string, std::string>(file, ""));
}

void Localisator::createFolders()
{
    for (auto &file : files)
    {
        std::string buferline = file.first;
        if (buferline.find("\\english") != std::string::npos)
            buferline.replace(buferline.find("\\english"), 8, "\\russian");
        buferline.replace(buferline.rfind("english.yml"), 11, "russian.yml");

        file.second = buferline;
        buferline.erase(buferline.rfind("\\"));
        std::filesystem::create_directories(buferline);
    }
}

int Localisator::localise(Mod mod)
{
    if (mod.getLocType() < 2)
        return mod.getLocType();

    addPaths(mod);
    createFolders();

    for (auto &file : files)
    {
        std::ifstream original(file.first);
        std::ofstream localised(file.second);
        std::string buferline;

        while (!original.eof())
        {
            getline(original, buferline);

            if (buferline.find("l_english:") != std::string::npos)
            {
                buferline.replace(buferline.find("l_english:"), 11, "\nl_russian:");
                localised << "#Automatically translated";
            }

            localised << buferline << '\n';
        }
    }

    return AUTO_LOCALISED;
}