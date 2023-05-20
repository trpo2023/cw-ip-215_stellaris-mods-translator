#include "src/parser.hpp"
#include "src/fileLocalise.hpp"
#include "src/log.hpp"

int main()
{
    std::cout << "Api key: ";
    std::string apiKey;
    getline(std::cin, apiKey);
    std::cout << endl;

    std::cout << "Mod path: ";
    std::string steamLibrary;
    getline(std::cin, steamLibrary);
    std::cout << endl;

    std::cout << "Program work type:" << endl
              << "0 - only make files" << endl
              << "1 - and translate eng files" << endl
              << "2 - and retranslate automatically translated" << endl
              << "3 - and retranslate all" << endl;
    int workingType;
    cin >> workingType;
    cout << endl;

    std::vector<paths> Localisations;
    Parser(Localisations, steamLibrary);

    for (paths path : Localisations)
    {
        int code = localise(path, apiKey, workingType);
        log(code);
    }
}