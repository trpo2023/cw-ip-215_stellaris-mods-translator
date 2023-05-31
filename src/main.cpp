#include "parser.hpp"
#include "fileLocalise.hpp"
#include "log.hpp"

int main()
{
    std::cout << "Api key: ";
    std::string apiKey;
    getline(std::cin, apiKey);
    std::cout << std::endl;

    std::cout << "Mod path: ";
    std::string modPath;
    getline(std::cin, modPath);
    std::cout << std::endl;

    std::cout << "Program work type:\n"
              << "0 - only make files\n"
              << "1 - and translate eng files\n"
              << "2 - and retranslate automatically translated\n"
              << "3 - and retranslate all\n";
    int workingType;
    std::cin >> workingType;
    std::cout << std::endl;

    std::vector<paths> Localisations;
    Parser(Localisations, modPath);

    for(paths path : Localisations)
    {
        int code = localise(path, apiKey, workingType);
        std::cout << log(code);
    }
}