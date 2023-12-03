#ifndef H_TRANSLATOR
#define H_TRANSLATOR

#include "localisator.hpp"

class Translator : public Localisator
{
    std::string apiKey;
    void connect();
    std::string translate(std::string str);

public:
    Translator(std::vector<std::string> files, std::string apiKey);
    bool localise() override;
};

#endif