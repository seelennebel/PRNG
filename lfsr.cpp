#include <iostream>

uint32_t lfsr (uint32_t* state)
{
    uint32_t start_state = *state;
    uint32_t lfsr = start_state;
    uint32_t bit;

    bit = ((lfsr >> 0 ) ^ (lfsr >> 10) ^ (lfsr >> 20) ^ (lfsr >> 31)) & 1u;
    lfsr = (lfsr >> 1) | (bit << 31);

    return lfsr;
}