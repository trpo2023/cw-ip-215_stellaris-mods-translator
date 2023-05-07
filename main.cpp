#include <iostream>

#include "src/parser.hpp"
#include "src/fileLocalise.hpp"

using namespace std;

int main()
{
    cout << "Api key: ";
    string API_KEY;
    getline(cin, API_KEY);
    cout << '\n';

    cout << "steam library path: ";
    string STEAM_LIBRARY;
    getline(cin, STEAM_LIBRARY);
    cout << '\n';

    vector<paths> Localisations;
    Parser(Localisations, STEAM_LIBRARY);

    for (paths path : Localisations)
    {
        int code = localise(path);
        // log(code);
    }
}