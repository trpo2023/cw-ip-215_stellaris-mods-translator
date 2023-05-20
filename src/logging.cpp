#include "logging.hpp"

void log(int code)
{
    switch(code)
    {
        case 0: cout << "file is succesfully translated"; break;
        case 1: cout << "file is succesfully transfered"; break;
        case 2: cout << "file is automatically translated before"; break;
        case 3: cout << "file is translated by mod autor"; break;
        case 4: cout << "file already exists"; break;
        case 5: cout << "invalid working type"; break;
    } 
}

int main()
{
    int code;
    log(code);
    return 0;
}