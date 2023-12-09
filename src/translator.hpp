#ifndef H_TRANSLATOR
#define H_TRANSLATOR

#include "localisator.hpp"
#include "database.hpp"

#include <curl/curl.h>

class Translator : public Localisator
{
    std::string apiKey;
    DataBase *db;
    CURL *curl;
    std::string translate(std::string str);

public:
    Translator();
    ~Translator();
    void connect();
    void setKey(std::string apiKey);
    int localise(Mod mod) override;
};

#endif