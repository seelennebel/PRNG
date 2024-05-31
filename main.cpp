#include "lfsr.h"
#include "utils.h"
#include "xor.h"

#include <cstring>
#include <fstream>
#include <filesystem>
#include <string>

bool exists_test0 (const std::string& name) {
    std::ifstream file(name.c_str());
    return file.good();
}

void generate_XOR ()
{
    if(!exists_test0(".seed.txt"))
    {
        std::ofstream outfile;
        outfile.open(".seed.txt", std::ios::app);
        uint32_t RN = RN_generator();
        uint32_t rn = xorshift(&RN);
        outfile << rn << "\n";
        std::cout << rn << "\n";
        outfile.close();
    }
    
    else
    {   
        std::ifstream infile;
        std::ofstream outfile;
        uint32_t value;

        infile.open(".seed.txt");
        while(infile >> value);
        infile.close();

        outfile.open(".seed.txt", std::ios::app);
        uint32_t r = xorshift(&value);
        outfile << r << "\n";
        std::cout << r << "\n";
        outfile.close();
    }
}

void test_XOR ()
{
    int i = 0;
    while (i < 25000)
    {
        generate_XOR();
        ++i;
    }
    std::ofstream test_file;
    test_file.open("test.txt", std::ios::out);

    test_file << "{";

    std::ifstream in_file;
    in_file.open(".seed.txt");
    in_file.seekg(0);
    std::string line;
    while(std::getline(in_file, line))
    {
        test_file << line << ",";
    }
    test_file << "}";
    test_file.close();
    in_file.close();
}

int main (int argc, char** argv) 
{

    if(argc == 1)
    {
        generate_XOR();
    }
    if(argc >= 2)
    {
        std::string arg = argv[1];
        if("-s" == arg)
        {
            std::ofstream file;
            file.open(".seed.txt", std::ios::trunc);
            file << argv[2] << "\n";
            file.close();
        }
    }
    return 0;
}