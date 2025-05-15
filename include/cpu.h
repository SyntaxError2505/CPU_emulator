#ifndef cpuem
#define cpuem

#include "ram.h"

class CPU{
    private:
    unsigned int programm_counter;

    int stack_a = 0;
    int stack_b = 0;
    int stack_c = 0;

    RAM memory;

    bool decode(){
        
    }

    bool fetch(){
        
    }

    public:

    void reset(){
        stack_a = 0;
        stack_b = 0;
        stack_c = 0;

        for(int i; i < 255; i++){
            memory.write(i, 0);
        }
    }

    void bindRAM(RAM &binding){
        memory = binding;
    }
};

#endif