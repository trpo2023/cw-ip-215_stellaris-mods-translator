#include "parser.hpp"
#include "localisator.hpp"

#include <iostream>

int main()
{
    std::cout << "Input mod path: ";
    std::string path;
    std::cin >> path;
    Parser parser(path);
    Mod mod = parser.parse();
    Localisator localisator(mod.getFiles());
    if(localisator.localise())
        std::cout << "The mod has been successfully translated";
    else std::cout << "The mod has already been translated";
}