#include <iostream>
#include <filesystem>

using namespace std;
using namespace filesystem;

void Parser(path mods_path)
{
    for(auto& entry : directory_iterator(mods_path))
    {
        if(is_directory(entry.status())) Parser(entry.path());

        else if(entry.path().string().find("_l_english.yml") != string::npos)
            cout << entry.path().string() << "\n";
    }
}

int main()
{
    path mods_path = "C:\\Program Files (x86)\\Steam\\steamapps\\workshop\\content\\281990";

    Parser(mods_path);

    return 0;
}