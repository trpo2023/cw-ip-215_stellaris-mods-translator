#include "translator.hpp"

void Translator::connect()
{
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
}

Translator::Translator()
    : db("translations.db") {}

Translator::~Translator()
{
    curl_easy_cleanup(curl);
    curl_global_cleanup();
}

void Translator::setKey(std::string apiKey)
{
    this->apiKey = apiKey;
}

std::string translatedText;
size_t callback(char *buf, size_t size, size_t nmemb, void *userdata)
{
    translatedText.append(buf, size * nmemb);
    return size * nmemb;
}

std::string Translator::translate(std::string textToTranslate)
{
    curl_slist *headers = NULL;

    std::string url = "https://translate.api.cloud.yandex.net/translate/v2/translate";
    std::string fromLang = "en";
    std::string toLang = "ru";

    curl = curl_easy_init();
    if (curl)
    {
        headers = curl_slist_append(headers, "Content-Type: application/json");
        headers = curl_slist_append(headers, ("Authorization: Api-Key " + apiKey).c_str());

        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);

        std::string post_data = "{\"texts\":[\"" + textToTranslate + "\"]," +
                                "\"targetLanguageCode\":\"" + toLang + "\"," +
                                "\"sourceLanguageCode\":\"" + fromLang + "\"}";

        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_data.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);

        curl_easy_perform(curl);
        curl_slist_free_all(headers);

        return translatedText.substr(translatedText.rfind(':') + 3,
                                     translatedText.rfind('"') -
                                         translatedText.rfind(':') - 3);
    }

    return translatedText;
}

int Translator::localise(Mod mod)
{
    if (mod.getLocType() == TRANSLATED || mod.getLocType() == UNTRANSLATABLE)
        return mod.getLocType();

    addPaths(mod);
    createFolders();

    for (auto &file : getFiles())
    {
        std::ifstream original(file.first);
        std::ofstream localised(file.second);
        std::string buferline;

        while (!original.eof())
        {
            getline(original, buferline);

            if (buferline.find("l_english:") != std::string::npos)
            {
                buferline.replace(buferline.find("l_english:"), 11, "\nl_russian:");
                localised << "#Automatically translated";
            }

            int firstQuote = buferline.find_first_of('\"');
            if (firstQuote == std::string::npos)
            {
                localised << buferline;
                continue;
            }
            int lastQuote = buferline.find_last_of('\"');
            std::string text = buferline.substr(firstQuote + 1, lastQuote - firstQuote - 1);

            localised << buferline.substr(0, firstQuote + 1);

            if (db.check(text))
                localised << db.getTranslation(text);

            else
            {
                std::string translated = translate(buferline.substr(firstQuote + 1, lastQuote - firstQuote - 1));
                localised << translated;
                db.add(text, translated);
            }

            localised << buferline.substr(lastQuote, buferline.length() - lastQuote + 1) << '\n';
        }
    }

    return AUTO_TRANSLATED;
}