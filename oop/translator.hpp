#ifndef H_TRANSLATOR
#define H_TRANSLATOR

#include "localisator.hpp"
#include "database.hpp"

class Translator : public Localisator
{
    std::string apiKey;
    DataBase *db;
    void connect();
    std::string translate(std::string str);

public:
    Translator(std::vector<std::string> files, std::string apiKey);
    ~Translator();
    bool localise() override;
};

#endif