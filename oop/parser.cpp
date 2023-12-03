#include "parser.hpp"

Parser::Parser(std::string path)
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

    if (!isTranslatable())
        throw std::runtime_error("Missing localisation files");

    std::vector<std::string> files;
    fillFiles(files, path);

    std::string id = path.substr(path.length() - 10);
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

    return Mod(path, id, name, image, files);
}