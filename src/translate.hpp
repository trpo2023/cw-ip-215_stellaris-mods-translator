#pragma once

#include <iostream>
#include <curl/curl.h>

size_t WriteCallback(char* buf, size_t size, size_t nmemb, void* userdata);
std::string translate(std::string str, std::string apiKey);