#pragma once

#include <fstream>

#include "paths.hpp"
#include "translate.hpp"

#define SUCCESFULLY_TRANSLATED 0
#define SUCCESFULLY_CREATED 1
#define FILE_ALREADY_TRANSLATED 2
#define FILE_TRANSLATED_BY_MOD_CREATOR 3
#define FILE_EXIST 4
#define UNCORRECT_WORKING_TYPE 5

int localise(paths paths, std::string apiKey, int workingType);