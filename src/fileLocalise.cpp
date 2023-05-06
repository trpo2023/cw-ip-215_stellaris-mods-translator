#include "fileLocalise.hpp"
#include "parser.hpp"
#include "translate.hpp"

int localise(paths paths)
{
    create_directory(paths.translate_path);

    string buferline = paths.original_path.substr(paths.original_path.rfind("\\"));
    buferline.replace(buferline.rfind("english.yml"), 11, "russian.yml");

    ifstream original(paths.original_path);
    ofstream localised(paths.translate_path + buferline);

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