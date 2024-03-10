#include <stdio.h>
#include <stdbool.h>

typedef enum {
    PSH,
    ADD,
    POP,
    SET,
    HLT
} InstructionSet;

const int program[] = {
    	PSH,
    	5,
    	PSH, 
    	6,
    	ADD,
    	POP,
    	HLT
};

int stack[256];
int stack_pointer = -1;
int instruction_pointer = 0;
bool running = true;

int print() {
	switch (program[instruction_pointer]) {
		case PSH:
			printf("%s \n", "PSH");
			break;
		case ADD:
			printf("%s \n", "ADD");
			break;
		case POP:
			printf("%s \n", "POP");
			break;
		case HLT:
			printf("%s \n", "HLT");
			break;			
		default:
			printf("%s \n", "value");
			break;
	}
}

int fetch() {
    return program[instruction_pointer];
}

void eval(int instr) {
    switch (instr) {
	    case HLT:
	        running = false;
	        break;
	    case PSH:
	    	stack_pointer++;
	    	stack[stack_pointer] = program[++instruction_pointer];
	    	break;   
    }
}

int main(int argc, char *argv[]) {
	while (running) {
		eval(fetch());
		print();
		instruction_pointer++;
	}
    
    return 0;
}
