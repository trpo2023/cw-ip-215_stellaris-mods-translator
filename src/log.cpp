#include "log.hpp"

void log(int code)
{
    switch(code)
    {
        case 0: cout << "file is succesfully translated\n"; break;
        case 1: cout << "file is succesfully transfered\n"; break;
        case 2: cout << "file is automatically translated before\n"; break;
        case 3: cout << "file is translated by mod autor\n"; break;
        case 4: cout << "file already exists\n"; break;
        case 5: cout << "invalid working type\n"; break;
    } 
}