#ifndef H_TRANSLATOR
#define H_TRANSLATOR

#include "localisator.hpp"
#include "database.hpp"

class Translator : public Localisator
{
    std::string apiKey;
    DataBase *db;
    void connect();
    void disconnect();
    std::string translate(std::string str);

public:
    Translator();
    ~Translator();
    void setKey(std::string apiKey);
    int localise(Mod mod) override;
};

#endif