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

    std::cout << "Program work type:" << endl
              << "0 - only make files" << endl
              << "1 - only translate eng files" << endl
              << "2 - only retranslate automatically translated" << endl
              << "3 - replace all" << endl;
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