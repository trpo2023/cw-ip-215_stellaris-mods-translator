#include "fileLocalise.hpp"

#define SUCCESFULLY_TRANSLATED 0
#define SUCCESFULLY_CREATED 1
#define FILE_ALREADY_TRANSLATED 2
#define FILE_TRANSLATED_BY_MOD_CREATOR 3
#define FILE_EXIST 4
#define UNCORRECT_WORKING_TYPE 5

int localise(paths path, std::string apiKey, int workingType)
{
    std::ifstream original(path.original_path);
    std::ifstream exist(path.translate_path);
    std::ofstream localised(path.translate_path);

    std::string buferline;

    if(workingType > 4 || workingType < 0)
        return UNCORRECT_WORKING_TYPE;

    if(exist.good() && workingType != 3)
    {
        if(workingType == 0) return FILE_EXIST;

        getline(exist, buferline);

        //if not retranslate automatically translated
        if(buferline.find("Automatically translated") != std::string::npos && workingType < 2)
            return FILE_ALREADY_TRANSLATED;

        do getline(exist, buferline);
        while (buferline.find(":") != std::string::npos);
        
        for(char ch : buferline)
            for(char rusCh : "йцукенгшщзхъфывапролджэячсмитьбюё")
                if(workingType < 3 && ch == rusCh) return FILE_TRANSLATED_BY_MOD_CREATOR;
    }

    while(!original.eof())
    {
        getline(original, buferline);

        if(buferline.find("l_english:") != std::string::npos)
        {
            buferline.replace(buferline.find("l_english:"), 11, "l_russian:");
            if(workingType != 0) buferline.append("# Automatically translated\n");
            else buferline.append("\n");
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