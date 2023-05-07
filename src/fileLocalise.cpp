#include "fileLocalise.hpp"
#include "translate.hpp"

int localise(paths path)
{
    ifstream original;
    original.open(path.original_path);

    ofstream localised;
    original.open(path.translate_path);

    string buferline = "";

    do getline(original, buferline);
    while (buferline.find(':') == string::npos);

    localised << "# translated last " << ctime(0) << '\n'
              << "l_russian:" << '\n';

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