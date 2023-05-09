#include <iostream>
using namespace std;
void log(int code){
    switch(code){
        case 0: cout << "file is succesfully transfered"; break;
        case 1: cout << "file transfered with problems"; break;
        case 2: cout << "file transfered partially"; break;
        case 3: cout << "file does not exist"; break;
        case 4: cout << "file is already transfered"; break;
    } 
}

int main(){
    int code;
    log(code);
    return 0;
}