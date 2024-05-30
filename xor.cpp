#include <iostream>
#include <bitset>
#include <map>
#include <unistd.h>
#include <chrono>
#include <ctime>

void RN_generator () 
{
    pid_t pid = getpid();
    std::chrono::system_clock::now().time_since_epoch()
}

uint32_t xorshift (uint32_t* state)
{
    uint32_t y = *state;
    y ^= (y << 13);
    y ^= (y >> 17);
    return (y ^= (y << 5)); 
}

void print_bits (uint32_t* bits)
{
    std::bitset<32> bit_set(*bits);
    std::cout << bit_set << "\n"; 
}

int get_last_bit (uint32_t* bits)
{
    std::bitset<32> bit_set(*bits);
    return bit_set[0];
}

void count_duplicates (uint32_t* arr, int size)
{
    std::map<int, int> mp;
    for(int i = 0; i < size; ++i)
    {
        if(mp.find(arr[i]) != mp.end())
        {
            mp[arr[i]] = 0;
        }
        else
        {
            mp[arr[i]] += 1;
        }
    }
    std::map<int, int>::iterator it;
    for(it = mp.begin(); it != mp.end(); it++)
    {
        std::cout << it -> first << " : " << it -> second << "\n";
    }
}

int main () 
{
    uint32_t state = 1;
    uint32_t RN = state;
    int period = 0;
    uint32_t arr[300000]; 

    print_bits(&state);
    do
    {
        RN = xorshift(&RN);
        ++period;

        std::cout << "last bit: "<< get_last_bit(&RN) << "     ";
        std::cout << "period: " << period << "     ";
        print_bits(&RN);
        //std::cout << RN << "\n";
    }
    while(period < 30);

    return 0;
}