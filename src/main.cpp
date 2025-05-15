#include <iostream>
#include "cpu.h"
#include "ram.h"

int main(){
    RAM memory;
    CPU processor;

    processor.bindRAM(memory);
    processor.reset();
    return 0;
}
