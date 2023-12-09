#include "translator.hpp"

Translator::Translator()
{
    db = new DataBase("translations.db");
}

Translator::~Translator()
{
    delete db;
}

void Translator::setKey(std::string apiKey)
{
    this->apiKey = apiKey;
}

int Translator::localise(Mod mod)
{
    if (mod.getLocType() == TRANSLATED || mod.getLocType() == UNTRANSLATABLE)
        return mod.getLocType();

    addPaths(mod);
    createFolders();

    for (auto &file : getFiles())
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