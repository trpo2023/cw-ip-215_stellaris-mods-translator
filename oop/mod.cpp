#include "mod.hpp"

Mod::Mod(std::string path, std::string id, std::string name, std::string image, std::vector<std::string> files)
{
    this->path = path;
    this->id = id;
    this->name = name;
    this->image = image;
    this->files = files;
}

std::string Mod::getPath()
{
    return path;
}

std::string Mod::getID()
{
    return id;
}

std::string Mod::getName()
{
    return name;
}

std::string Mod::getImage()
{
    return image;
}

std::vector<std::string> Mod::getFiles()
{
    return files;
}