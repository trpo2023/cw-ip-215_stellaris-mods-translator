#include "mod.hpp"

Mod::Mod()
{
    locType = -1;
}

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

std::string Mod::convertLocType()
{
    int type = getLocType();

    switch (type)
    {
    case UNTRANSLATABLE:
        return "the mod doesn't need translation";

    case NOT_TRANSLATED:
        return "the mod is not translated";

    case AUTO_LOCALISED:
        return "the mod localised automatically";

    case AUTO_TRANSLATED:
        return "the mod translated automatically";
        
    case TRANSLATED:
        return "the mod has already been translated by the author";

    default: return "incorrect input";
    }
}

std::vector<std::string> Mod::getFiles()
{
    return files;
}