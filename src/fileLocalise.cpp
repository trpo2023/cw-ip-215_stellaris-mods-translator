#include "fileLocalise.hpp"
#include "translate.hpp"

int localise(paths path)
{
    ifstream original(path.original_path);
    ofstream localised(path.translate_path);

    string buferline;

    while(!original.eof())
    {
        getline(original, buferline);

        if(buferline.find("l_english:") != string::npos)
        {
            buferline.replace(buferline.find("l_english:"), 11, "l_russian:");
            buferline.append("# Automatically translated\n");
        }

        int firstQuote = buferline.find_first_of('\"');
        if (firstQuote == string::npos) 
        {
            localised << buferline;
            continue;
        }
        int lastQuote = buferline.find_last_of('\"');

        localised << buferline.substr(0, firstQuote)
                  << translate(buferline.substr(firstQuote, lastQuote - firstQuote))
                  << buferline.substr(lastQuote, buferline.length() - lastQuote + 1) << "\n";
    }
}