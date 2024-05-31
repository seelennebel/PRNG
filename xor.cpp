#include "xor.h"

uint32_t xorshift (uint32_t* state)
{
    uint32_t y = *state;
    y ^= (y << 13);
    y ^= (y >> 17);
    return (y ^= (y << 5)); 
}
