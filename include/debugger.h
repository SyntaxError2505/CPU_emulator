#ifndef debuggerem
#define debuggerem

#include<string>
#include<iostream>

std::string errors[3] = {"Unknown opcode",
                         "Wrong type of adress for operation",
                         "Out of memory/cache range"};

void error(int code, int ln){
    std::cout << "Error: " << errors[code] << " Ln: " << ln << std::endl;
}

#endif