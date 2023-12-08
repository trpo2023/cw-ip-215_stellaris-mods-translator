#include "parser.hpp"
#include "localisator.hpp"

#include <iostream>

int main()
{
    std::cout << "Input mod path: ";
    std::string path;
    std::cin >> path;

    Parser parser;
    parser.setPath(path);
    Mod mod = parser.parse();

    Localisator localisator;
    localisator.setMod(mod);
    int code = localisator.localise();
    switch (code)
    {
    case TRANSLATED:
        std::cout << "the mod has already been translated by the author";
        break;

    case UNTRANSLATABLE:
        std::cout << "the mod doesn't need translation";
        break;

    case AUTO_LOCALISED:
        mod.setLocType(code);
        std::cout << "the mod was successfully localised";
    }
}