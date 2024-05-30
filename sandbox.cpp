#include <iostream>
#include <unistd.h>
#include <ctime>
#include <sstream>
#include <chrono>

std::bitset<32> convertTo_32_bits (uint32_t* bits)
{
    std::bitset<32> bit_set(*bits);
    return bit_set;
}

int get_last_bit (uint32_t* bits)
{
    std::bitset<32> bit_set(*bits);
    return bit_set[0];
}

uint32_t lfsr_32bit ()
{
    uint32_t start_state = ((long)std::time(0) ^ getpid()) >> 3; 
    uint32_t position = getpid() >> 4;
    std::cout << "PID: " << position << "\n";
    std::cout << "start state: " << start_state << "\n";
    uint32_t lfsr = start_state;
    uint32_t bit;

    uint32_t binary_sequence[300000];
    std::bitset<32> RN;

    int period = 0;

    do
    {
        bit = ((lfsr >> 0 ) ^ (lfsr >> 10) ^ (lfsr >> 20) ^ (lfsr >> 31)) & 1u;
        lfsr = (lfsr >> 1) | (bit << 31);
        binary_sequence[period] = get_last_bit(&lfsr);
        ++period;

        //std::cout << "period" << period << "      " << convertTo_32_bits(&lfsr) << "      " << get_last_bit(&lfsr) << "\n"; 
    }
    while (period < 300000);

    for(int i = 0; i < sizeof(binary_sequence) / sizeof(*binary_sequence); ++i)
    {
        //std::cout << "index: " << i << "      " << binary_sequence[i] << "\n";
    }

    for(int i = 0; i < 32; ++i)
    {
        //std::cout << "position: " << position << "\n";
        RN[i] = binary_sequence[position];
        ++position;
    }
    std::cout << RN.to_ulong();
    return RN.to_ulong();
}

int main () 
{
    /*
    long t = (long)std::time(0);
    long pid = getpid();

    uint64_t res = t ^ pid;
    res /= pid;

    std::cout << t;
    std::cout << res;
    */
   lfsr_32bit();
}