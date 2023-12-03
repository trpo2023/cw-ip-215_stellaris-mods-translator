#include "translator.hpp"

void Translator::connect()
{

}

std::string Translator::translate(std::string str)
{
    return str;
}

Translator::Translator(std::vector<std::string> files, std::string apiKey) : Localisator(files)
{
    this->apiKey = apiKey;
}

bool Translator::localise()
{
    if (!createFolders())
        return 0;

    connect();

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
            if (firstQuote == (int)std::string::npos)
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

    return 1;
}