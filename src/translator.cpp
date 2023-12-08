#include "translator.hpp"

Translator::Translator(std::string apiKey)
{
    this->apiKey = apiKey;
    db = new DataBase("path");
}

Translator::~Translator()
{
    delete db;
}