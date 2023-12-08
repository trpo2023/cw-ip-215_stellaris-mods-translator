#include "parser.hpp"

void Parser::setPath(std::string path)
{
    this->path = path;
}

bool Parser::isTranslatable()
{
    for (auto &entry : std::filesystem::directory_iterator(path))
        if (entry.path().string().find("localisation") != std::string::npos)
            return 1;

    return 0;
}

int Parser::locType(std::string file)
{
    std::ifstream check(file);
    if (!check.good())
        return NOT_TRANSLATED;

    std::string buferline;
    getline(check, buferline);
    int type;
    if (buferline.find("#Automatically translated") != std::string::npos)
        type = AUTO_LOCALISED;

    while (getline(check, buferline))
        for (char ch : buferline)
            if (ch >= '\xd0' && ch <= '\xef')
            {
                if (type == AUTO_LOCALISED)
                    return AUTO_TRANSLATED;
                else
                    return TRANSLATED;
            }

    return type;
}

void Parser::fillFiles(std::vector<std::string> &files, std::filesystem::path path)
{
    for (auto &entry : std::filesystem::directory_iterator(path))
    {
        if (std::filesystem::is_directory(entry.status()))
            fillFiles(files, entry.path());

        if (entry.path().string().find("_l_english.yml") != std::string::npos)
            files.push_back(entry.path().string());
    }
}

Mod Parser::parse()
{
    if (!std::filesystem::exists(path))
        throw std::runtime_error("Invalid path");

    int type;
    std::vector<std::string> files;
    if (!isTranslatable())
        type = UNTRANSLATABLE;

    else
    {
        fillFiles(files, path);

        std::string buferline = files[0];
        if (buferline.find("\\english") != std::string::npos)
            buferline.replace(buferline.find("\\english"), 8, "\\russian");
        buferline.replace(buferline.rfind("english.yml"), 11, "russian.yml");

        type = locType(buferline);
    }

    std::string image = path + "\\" + "thumbnail.png";

    std::string name;
    std::string descriptor = path + "\\" + "descriptor.mod";
    std::ifstream file(descriptor);
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            std::size_t pos = line.find("name=\"");
            if (pos != std::string::npos)
            {
                pos += 6;
                std::size_t endPos = line.find_first_of('\"', pos);
                name = line.substr(pos, endPos - pos);
            }
        }
        file.close();
    }

    return Mod(name, image, type, files);
}