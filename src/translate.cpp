#include "translate.hpp"

std::string translatedText;

size_t WriteCallback(char* buf, size_t size, size_t nmemb, void* userdata) 
{
    translatedText.append(buf, size * nmemb);
    return size * nmemb;
}

std::string translate(std::string textToTranslate, std::string apiKey) 
{
    CURL* curl;
    curl_slist* headers = NULL;

    std::string url = "https://translate.api.cloud.yandex.net/translate/v2/translate";
    std::string fromLang = "en";
    std::string toLang = "ru";

    curl = curl_easy_init();
    if(curl) 
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
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

        curl_easy_perform(curl);
        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);

        return translatedText.substr(translatedText.rfind(':') + 3,
                                     translatedText.rfind('"') - 
                                     translatedText.rfind(':') - 3);
    }
    else return textToTranslate;
}