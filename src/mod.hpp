#ifndef H_MOD
#define H_MOD

#include <string>
#include <vector>

#define UNTRANSLATABLE 0
#define NOT_TRANSLATED 1
#define AUTO_LOCALISED 2
#define AUTO_TRANSLATED 3
#define TRANSLATED 4

class Mod
{
    std::string name;
    std::string image;
    int locType;
    std::vector<std::string> files;

public:
    Mod(std::string name,
        std::string image,
        int locType,
        std::vector<std::string> files);

    std::string getName();
    std::string getImage();
    int getLocType();
    void setLocType(int locType);
    std::vector<std::string> getFiles();
};

#endif