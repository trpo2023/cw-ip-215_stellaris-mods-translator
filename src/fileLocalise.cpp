#include "fileLocalise.hpp"

int localise(paths path, std::string apiKey, int workingType)
{
    std::ifstream original(path.originalPath);
    std::ifstream exist(path.translatePath);

    std::string buferline;

    if(workingType > 4 || workingType < 0) return UNCORRECT_WORKING_TYPE;

    if(exist.good() && workingType != 3)
    {
        if(workingType == 0) return FILE_EXIST;

        getline(exist, buferline);

        if(buferline.find("# Automatically translated") != std::string::npos && workingType < 2)
            return FILE_ALREADY_TRANSLATED;

        while(getline(exist, buferline))
            for(char ch : buferline)
                for(char rusCh : "йцукенгшщзхъфывапролджэячсмитьбюё")
                    if(ch == rusCh) return FILE_TRANSLATED_BY_MOD_CREATOR;
    }

    std::ofstream localised(path.translatePath);

    while(!original.eof())
    {
        getline(original, buferline);

        if(buferline.find("l_english:") != std::string::npos)
        {
            buferline.replace(buferline.find("l_english:"), 11, "\nl_russian:\n");
            if(workingType != 0) localised << "# Automatically translated";
        }

        int firstQuote = buferline.find_first_of('\"');
        if(firstQuote == (int)std::string::npos) 
        {
            localised << buferline;
            continue;
        }
        int lastQuote = buferline.find_last_of('\"');

        if(workingType != 0)
            localised << buferline.substr(0, firstQuote + 1)
                      << translate(buferline.substr(firstQuote + 1, lastQuote - firstQuote - 1), apiKey)
                      << buferline.substr(lastQuote, buferline.length() - lastQuote + 1) << "\n";
        
        else localised << buferline << "\n";
    }

    switch(workingType)
    {
        case 0: return SUCCESFULLY_CREATED;
        default: return SUCCESFULLY_TRANSLATED;
    }
}