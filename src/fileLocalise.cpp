#include "fileLocalise.hpp"
#include "translate.hpp"

int localise(paths path, std::string apiKey)
{
    std::ifstream original(path.original_path);
    std::ofstream localised(path.translate_path);

    std::string buferline;

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

        localised << buferline.substr(0, firstQuote + 1)
                  << translate(buferline.substr(firstQuote + 1, lastQuote - firstQuote - 1), apiKey)
                  << buferline.substr(lastQuote, buferline.length() - lastQuote + 1) << "\n";
    }
}