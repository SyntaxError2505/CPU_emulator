#include <iostream>
#include "emulator.h"

int main(){
    CPU processor;
    RAM memory;

    std::cout << "reseting memory\n";
    processor.reset(memory);

    std::cout << "making program\n";
    //loads the number 69 (funny) to the cpus internal register a
    int program[] = {1, 14, 0, 16, 69};


    std::cout << "loading program\n";
    //load the program into ram
    for(int i = 0; i < sizeof(program)/sizeof(int); i++){
        memory.add_command(i, program[i]);
    }

    std::cout << "Cycle\n";
   
    //execute the program
    for(int i = 0; i < 5; i++){
        std::cout << "cycle started\n";
        processor.cycle(memory);
        std::cout << "cycle completed\n";
    }

    std::cout << processor.get_stack(0);

    return 0;
}