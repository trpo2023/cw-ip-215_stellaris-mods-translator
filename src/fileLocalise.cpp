#include "fileLocalise.hpp"
#include "translate.hpp"

int localise(paths path)
{
    create_directory(path.translate_path);

    string buferline = path.original_path.substr(path.original_path.rfind("\\"));
    buferline.replace(buferline.rfind("english.yml"), 11, "russian.yml");
    buferline = path.translate_path + buferline;

    ifstream exist(buferline);
    
    if(!exist.good())
    {
        ifstream original(path.original_path);
        ofstream localised(buferline);

        while(!original.eof())
        {
            getline(original, buferline);

            int firstQuote = buferline.find_first_of('\"');
            if (firstQuote == string::npos) 
            {
                localised << buferline;
                continue;
            }
            int lastQuote = buferline.find_last_of('\"');

            localised << buferline.substr(0, firstQuote)
                      << translate(buferline.substr(firstQuote, lastQuote - firstQuote))
                      << buferline.substr(lastQuote, buferline.length() - lastQuote + 1);
        }
    }
}