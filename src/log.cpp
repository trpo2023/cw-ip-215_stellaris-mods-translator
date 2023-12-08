#include "log.hpp"

std::string log(int code)
{
    switch(code)
    {
        case 0: return "file is succesfully translated\n"; break;
        case 1: return "file is succesfully transfered\n"; break;
        case 2: return "file is automatically translated before\n"; break;
        case 3: return "file is translated by mod autor\n"; break;
        case 4: return "file already exists\n"; break;
        case 5: return "invalid working type\n"; break;
    } 
}