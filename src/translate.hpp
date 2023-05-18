#pragma once

#include <iostream>
#include <curl/curl.h>

using namespace std;

size_t WriteCallback(char* buf, size_t size, size_t nmemb, void* userdata);

string translate(string str, string apiKey);