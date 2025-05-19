#ifndef cpuem
#define cpuem

#include "ram.h"

class CPU{
    private:
    unsigned int program_counter = 0;
    unsigned int current_operation = 0;
    unsigned int current_flag = 0;

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

    void cycle(RAM& memory){
        int operation = fetch(memory);
        switch(operation){
            case 0:
            //nop
            case 1:
            program_counter++;
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
            case 13:
        }
        program_counter++;
    }
};

#endif