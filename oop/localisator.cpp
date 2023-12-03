#include "localisator.hpp"

Localisator::Localisator(std::vector<std::string> files)
{
    for (auto &file : files)
        this->files.insert(std::pair<std::string, std::string>(file, ""));
}

std::map<std::string, std::string> Localisator::getFiles()
{
    return files;
}

int Localisator::isTranslated(std::string file)
{
    std::ifstream check(file);

    if (!check.good())
        return FILE_NOT_FOUND;

    std::string buferline;
    getline(check, buferline);
    while (getline(check, buferline))
        for (char ch : buferline)
            if (ch >= '\xd0' && ch <= '\xef')
                return FILE_TRANSLATED;

    return FILE_NOT_TRANSLATED;
}

bool Localisator::createFolders()
{
    for (auto &file : files)
    {
        std::string buferline = file.first;
        if (buferline.find("\\english") != std::string::npos)
            buferline.replace(buferline.find("\\english"), 8, "\\russian");
        buferline.replace(buferline.rfind("english.yml"), 11, "russian.yml");
        int code = isTranslated(buferline);

        if (code == FILE_TRANSLATED)
            return 0;
        
        if (code == FILE_NOT_TRANSLATED)
            return 1;

        file.second = buferline;
        buferline.erase(buferline.rfind("\\"));
        std::filesystem::create_directory(buferline);
    }

    return 1;
}

bool Localisator::localise()
{
    if(!createFolders())
        return 0;

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

            localised << buferline << "\n";
        }
    }

    return 1;
}