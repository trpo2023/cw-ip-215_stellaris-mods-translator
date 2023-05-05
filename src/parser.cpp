#include <iostream>
#include <filesystem>
#include <vector>

using namespace std;
using namespace filesystem;

struct paths
{
    string original_path;
    string translate_path;
};

string TranslatePath(string path)
{
    if(path.find("\\english") != string::npos)
        path.replace(path.find("\\english"), 8, "\\russian");

    return path.erase(path.rfind("\\"));;
}

void Parser(vector<paths> &Localisations, path mods_path)
{
    for(auto& entry : directory_iterator(mods_path))
    {
        if(is_directory(entry.status())) Parser(Localisations, entry.path());

        else if(entry.path().string().find("_l_english.yml") != string::npos)
        {
            paths localisation_paths;
            localisation_paths.original_path = entry.path().string();
            localisation_paths.translate_path = TranslatePath(entry.path().string());
            Localisations.push_back(localisation_paths);
        }
    }
}

int main()
{
    vector<paths> Localisations;
    path mods_path = "C:\\Program Files (x86)\\Steam\\steamapps\\workshop\\content\\281990";

    Parser(Localisations, mods_path);
    
    for(paths i : Localisations)
        cout << i.original_path << "\n"
             << i.translate_path << "\n";

    return 0;
}