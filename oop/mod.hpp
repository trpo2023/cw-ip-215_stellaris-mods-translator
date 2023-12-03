#ifndef H_MOD
#define H_MOD

#include <string>
#include <vector>

class Mod
{
    std::string path;
    std::string id;
    std::string name;
    std::string image;
    std::vector<std::string> files;

public:
    Mod(std::string path,
        std::string id,
        std::string name,
        std::string image,
        std::vector<std::string> files);

    std::string getPath();
    std::string getID();
    std::string getName();
    std::string getImage();
    std::vector<std::string> getFiles();
};

#endif