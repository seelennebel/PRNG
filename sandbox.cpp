#include <iostream>
#include <unistd.h>
#include <ctime>
#include <sstream>

int get_RN_PID ()
{
    bool found_number = false;
    int pid = getpid();
    while(found_number == false)
    {
        if(pid < 991)
        {
            found_number = true;
            return pid;
        }
        else
        {
            //pid  2;
        }
    }
    return 0;
}

int main () 
{
    //std::cout << get_RN_PID();
    //std::cout << (994 % 1000);

    std::time_t result = std::time(nullptr);
    const char* t = std::ctime(&result);
    const char* ss = "";
    ss += t[17]; 
    ss += t[18];
    std::cout << *ss + 46; 
    return 0;

}