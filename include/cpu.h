#ifndef cpuem
#define cpuem

#include "ram.h"

class CPU{
    private:
    unsigned int program_counter = 0;
    unsigned int current_operation = 0;
    unsigned int current_flag = 0;

    int stack[3];

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
        stack[0] = 0;
        stack[1] = 0;
        stack[2] = 0;

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
            int cache;
            int value;
            program_counter++;
            if(fetch(memory) == 14){
                program_counter++;
                cache = fetch(memory);
                program_counter++;
                if(fetch(memory) == 14){
                    program_counter++;
                    value = cache[stack[fetch(memory)]];
                }
            }
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