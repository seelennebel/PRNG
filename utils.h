#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <unistd.h>
#include <chrono>
#include <bitset>

using namespace std::chrono;

uint32_t RN_generator();

void print_bits (uint32_t* bits);

int get_last_bit (uint32_t* bits);

std::bitset<32> convertTo_32_bits (uint32_t* bits);

#endif