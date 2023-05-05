#include <iostream>
#include <filesystem>

using namespace std;
using namespace filesystem;

string TranslatePath(string path)
{
    if(path.find("\\english") != string::npos)
        path.replace(path.find("\\english"), 8, "\\russian");
    return path.erase(path.rfind("\\"));;
}

void Parser(path mods_path)
{
    for(auto& entry : directory_iterator(mods_path))
    {
        if(is_directory(entry.status())) Parser(entry.path());

        else if(entry.path().string().find("_l_english.yml") != string::npos)
        {
            cout << entry.path().string() << "\n"
                 << TranslatePath(entry.path().string()) << "\n";
        }
    }
}

int main()
{
    path mods_path = "C:\\Program Files (x86)\\Steam\\steamapps\\workshop\\content\\281990";

    Parser(mods_path);

    return 0;
}