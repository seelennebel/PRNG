#include <iostream>
#include <bitset>
#include <cstdint>

void print_array_char (char* arr, size_t size)
{
    for(size_t i = 0; i < size; ++i)
    {
        std::cout << arr[i];
    }
    std::cout << "\n";
}

void RN_generator (char* arr, size_t size) 
{
    int n = 0;
    print_array_char(arr, size);
    while(n < 4)
    {
        for(int i = 0; i < size; ++i)
        {
            std::cout << (*arr >> 1) << "\n";
        }
        //print_array_char(arr, size);
        ++n;
    }
}

int main (int argc, char** argv)
{
    /*
    char arr[4];
    for(int i = 0; i < 4; ++i)
    {
            arr[i] = argv[1][i];
    }
    */

    //RN_generator(arr, sizeof(arr));
    uint32_t start_state = 0xB3F531A7;
    uint32_t lfsr = start_state;
    uint32_t bit;

    int period = 0;
// 10100101110100101100111111010100
    while(period < 1024)
    {
        std::bitset<32> neew(lfsr);
        std::cout << "period: " << period << " " << neew << "\n";

        bit = lfsr ^ (lfsr >> 1) & 1u;
        lfsr = (lfsr >> 1) | (bit << 31);

        ++period;
    }
    std::cout << period;
    return 0;
}