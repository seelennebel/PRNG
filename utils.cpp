#include "utils.h"

uint32_t RN_generator() 
{
    pid_t pid = getpid();
    milliseconds ms = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    uint32_t ms_long = ms.count();
    return (ms_long >>= pid);
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

std::bitset<32> convertTo_32_bits (uint32_t* bits)
{
    std::bitset<32> bit_set(*bits);
    return bit_set;
}