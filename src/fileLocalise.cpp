#include "fileLocalise.hpp"
#include "translate.hpp"

#define FILE_EXIST 4
#define FILE_ALREADY_TRANSLATED 4
#define FILE_TRANSLATED_BY_MOD_CREATOR 4

int localise(paths path, std::string apiKey, int workingType)
{
    std::ifstream original(path.original_path);
    std::fstream localised(path.translate_path);

    std::string buferline;

    if(localised.good())
    {
        if (workingType == 0)
        {
            return FILE_EXIST;
        }

        getline(localised, buferline);

        if (buferline.find("Automatically translated") != std::string::npos &&
            workingType < 2) //if not retranslate automatically translated
        {
            return FILE_ALREADY_TRANSLATED;
        }

        do getline(localised, buferline);
        while (buferline.find(":") != std::string::npos)

        if (!Regex.IsMatch(buferline, @"\p{IsCyrillic}") &&
        // russian symbols check
            workingType < 3) // if not retranslate all
        {
            return FILE_TRANSLATED_BY_MOD_CREATOR;
        }
        localised.seekg(0); // return to first symbol
    }

    while(!original.eof())
    {
        getline(original, buferline);

        if(buferline.find("l_english:") != std::string::npos)
        {
            buferline.replace(buferline.find("l_english:"), 11, "l_russian:");
            buferline.append("# Automatically translated\n");
        }

        int firstQuote = buferline.find_first_of('\"');
        if (firstQuote == std::string::npos) 
        {
            localised << buferline;
            continue;
        }
        int lastQuote = buferline.find_last_of('\"');

        if (workingType != 0)
        {
            localised << buferline.substr(0, firstQuote + 1)
                      << translate(buferline.substr(firstQuote + 1, lastQuote - firstQuote - 1), apiKey)
                      << buferline.substr(lastQuote, buferline.length() - lastQuote + 1) << "\n";
        }
        else
        {
            localised << buferline;
        }
    }
}