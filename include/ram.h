#ifndef ramem
#define ramem

class RAM{
    private:
    //255 bytes of memory
    int memory[255];
    //on kilobyte of program memory on ram
    int program[1000];

    public:
    //write to memory
    void write(unsigned int adress, unsigned int data){
        memory[adress] = data;
    }

    //read from memory
    int read(unsigned int adress){
        return memory[adress];
    }

    //add a command
    void add_command(int line, unsigned int opcode){
        if(line >= 1000){
            program[line] = opcode;
        }
    }

    //read from program memory
    int fetch(int count){
        return program[count];
    }
};

#endif