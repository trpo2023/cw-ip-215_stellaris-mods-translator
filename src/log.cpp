#include "log.hpp"

void log(int code)
{
    switch(code)
    {
        case 0: std::cout << "file is succesfully translated\n"; break;
        case 1: std::cout << "file is succesfully transfered\n"; break;
        case 2: std::cout << "file is automatically translated before\n"; break;
        case 3: std::cout << "file is translated by mod autor\n"; break;
        case 4: std::cout << "file already exists\n"; break;
        case 5: std::cout << "invalid working type\n"; break;
    } 
}