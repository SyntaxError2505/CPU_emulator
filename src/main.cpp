#include <iostream>
#include "cpu.h"
#include "ram.h"

int main(){
    RAM memory;
    CPU processor;

    processor.reset(memory);

    return 0;
}
