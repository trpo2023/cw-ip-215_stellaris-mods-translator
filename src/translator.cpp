#include "translator.hpp"

void Translator::connect()
{
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
}

void Translator::disconnect()
{
    curl_easy_cleanup(curl);
    curl_global_cleanup();
}

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

std::string Translator::translate(std::string str)
{
    return str;
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

            int firstQuote = buferline.find_first_of('\"');
            if (firstQuote == std::string::npos)
            {
                localised << buferline;
                continue;
            }
            int lastQuote = buferline.find_last_of('\"');

            localised << buferline.substr(0, firstQuote + 1)
                      << translate(buferline.substr(firstQuote + 1, lastQuote - firstQuote - 1))
                      << buferline.substr(lastQuote, buferline.length() - lastQuote + 1) << "\n";
        }
    }

    return AUTO_TRANSLATED;
}