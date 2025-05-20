#ifndef cpuem
#define cpuem

#include "ram.h"

class CPU{
    private:
    unsigned int program_counter = 0;

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
        program_counter = 0;

        stack[0] = 0;
        stack[1] = 0;
        stack[2] = 0;

        for(int i = 0; i <= 255; i++){
            memory.write(i, 0);
        }

        for(int i = 0; i <= 1000; i++){
            memory.add_command(i, 0);
        }
    }

    int get_stack(int adress){
        return stack[adress];
    }

    bool cycle(RAM& memory){
        int operation = fetch(memory);

        switch(operation){
            case 0:
            //nop
            break;

            case 1:
            //load int stack
            program_counter++;

            if(fetch(memory) == 14){
                int cache;
                int value;

                program_counter++;
                cache = fetch(memory);
                program_counter++;
                
                if(fetch(memory) == 14){
                    program_counter++;
                    value = stack[cache];
                }
                else if(fetch(memory) == 15){
                    program_counter++;
                    value = read(memory, fetch(memory));
                }
                else if(fetch(memory) == 16){
                    program_counter++;
                    value = fetch(memory);
                }

                stack[cache] = value;
            }
            break;
            case 2:
            //write into memory
            program_counter++;

            if(fetch(memory) == 15){
                int adress;
                int value;

                program_counter++;
                adress = fetch(memory);
                program_counter++;

                if(fetch(memory) == 14){
                    program_counter++;
                    value = stack[fetch(memory)];
                }
                else if(fetch(memory) == 15){
                    program_counter++;
                    value = read(memory, fetch(memory));
                }
                else if(fetch(memory) == 16){
                    program_counter++;
                    value = fetch(memory);
                }

                write(memory, adress, value);
            }

            break;
            
            case 3:
            if(operation == 3){
                int value_a;
                int value_b;
                int adress;

                program_counter++;

                if(fetch(memory) == 14){
                    program_counter++;
                    value_a = stack[fetch(memory)];

                    program_counter++;
                    if(fetch(memory) == 14){
                        program_counter++;
                        value_b = stack[fetch(memory)];

                        program_counter++;
                        if(fetch(memory) == 14){
                            program_counter++;
                            adress = fetch(memory);
                        }
                    }

                    stack[adress] = value_a + value_b;
                }
            }
            break;

            case 4:
            
            break;

            case 5:

            break;

            case 6:

            break;

            case 7:

            break;

            case 8:

            break;

            case 9:

            break;

            case 10:

            break;

            case 11:

            break;

            case 12:

            break;

            case 13:

            break;

            case 17:
            return true;
            break;
        }

        program_counter++;
        return false;
    }
};

#endif