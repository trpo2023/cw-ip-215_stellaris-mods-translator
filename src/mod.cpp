#include "mod.hpp"

Mod::Mod(std::string name, std::string image, int locType, std::vector<std::string> files)
{
    this->name = name;
    this->image = image;
    this->locType = locType;
    this->files = files;
}

std::string Mod::getName()
{
    return name;
}

std::string Mod::getImage()
{
    return image;
}

int Mod::getLocType()
{
    return locType;
}
void Mod::setLocType(int locType)
{
    this->locType = locType;
}

std::vector<std::string> Mod::getFiles()
{
    return files;
}