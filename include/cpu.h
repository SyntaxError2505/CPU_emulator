#ifndef cpuem
#define cpuem

#include "ram.h"

class CPU{
    private:
    unsigned int program_counter = 0;
    unsigned int current_operation = 0;

    int stack_a = 0;
    int stack_b = 0;
    int stack_c = 0;

    int fetch(RAM& memory){
        return memory.fetch(program_counter);
    }

    int read(RAM& memory, int adress){
        return memory.read(adress);
    }

    void write(RAM& memory, int adress, int data){
        memory.write(adress, data);
    }

    public:
    void reset(RAM& memory){
        stack_a = 0;
        stack_b = 0;
        stack_c = 0;

        for(int i; i <= 255; i++){
            memory.write(i, 0);
        }
    }

    void cycle(){
        program_counter++;
    }
};

#endif