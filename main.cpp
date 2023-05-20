#include "src/parser.hpp"
#include "src/fileLocalise.hpp"
#include "src/logging.hpp"

int main()
{
    std::cout << "Api key: ";
    std::string apiKey;
    getline(std::cin, apiKey);
    std::cout << '\n';

    std::cout << "Steam library path: ";
    std::string steamLibrary;
    getline(std::cin, steamLibrary);
    std::cout << '\n';

    std::vector<paths> Localisations;
    Parser(Localisations, steamLibrary);

    for (paths path : Localisations)
    {
        int code = localise(path, apiKey);
        log(code);
    }
}