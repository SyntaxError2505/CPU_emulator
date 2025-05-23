#include <iostream>
#include "emulator.h"

int main(){
    CPU processor;
    RAM memory;
    bool quit = false;

    std::cout << "reseting memory\n";
    processor.reset(memory);

    std::cout << "making program\n";

    int program[] = {1, 14, 0, 16, 2, 1, 14, 1, 16, 3, 3, 14, 0, 14, 1, 14, 2, 2, 15, 0, 14, 2, 17};


    std::cout << "loading program\n";
    //load the program into ram
    for(int i = 0; i < sizeof(program)/sizeof(int); i++){
        memory.add_command(i, program[i]);
    }

    std::cout << "Cycle\n";
   
    //execute the program
    while(!quit){
        quit = processor.cycle(memory);
    }

    std::cout << memory.read(0);
    return 0;
}