#include <stdio.h>
#include <stdbool.h>

#define stack_pointer (registers[STACK_POINTER]);
#define instruction_pointer (registers[INSTRUCTION_POINTER]);

typedef enum {
    PSH,
    ADD,
    POP,
    SET,
    HLT
} InstructionSet;

typedef enum {
   A, INSTRUCTION_POINTER, STACK_POINTER,
   NUM_OF_REGISTERS
} Registers;

const int VALUE_A = 45; // replace by any int value
const int VALUE_B = 12; // replace by any int value
const int EXPECTED_RESULT = VALUE_A + VALUE_B;
const int program[] = {
    	PSH,
    	VALUE_A,
    	PSH, 
    	VALUE_B,
    	ADD,
    	POP,
    	HLT
};


int stack[3];
int registers[NUM_OF_REGISTERS];
bool running = true;

void print() {
	printf("\n EOC \n");
	printf("SP : : %i \n", registers[STACK_POINTER]);
	printf("IP : : %i \n", registers[INSTRUCTION_POINTER]);
	printf("A register : %i \n\n", registers[A]);
}

int fetch() {
    return program[registers[INSTRUCTION_POINTER]];
}

void eval(int instr) {
    switch (instr) {
	    case HLT:
	    	printf("HLT \n");

	        running = false;
	        
	        break;
	    case PSH:
	    	stack[registers[STACK_POINTER]] = program[registers[INSTRUCTION_POINTER] + 1];
	    	registers[STACK_POINTER]++;
	    	
	    	printf("PSH %i \n", stack[registers[STACK_POINTER] - 1]);

	    	break;
	    case POP:
	    	registers[A] = stack[registers[STACK_POINTER]];
	        registers[STACK_POINTER]--;

			printf("POP last value in stack, put it in A register, value = %i \n", registers[A]);

	    	break;
	    case ADD:	    	
	    	int a = stack[registers[STACK_POINTER] - 1];
	    	int b = stack[registers[STACK_POINTER] - 2];

	    	int result = a + b;
	    	
	    	stack[registers[STACK_POINTER]] = result;

	    	printf("ADD %i to %i \n", a, b);

	    	break;
	    default:
	    	printf("... \n");

	    	break;			   
    }
}

int main(int argc, char *argv[]) {
	printf("\n FC \n");
	printf("SP : %i \n", registers[STACK_POINTER]);
	printf("IP : %i \n", registers[INSTRUCTION_POINTER]);
	printf("A register : %i \n\n", registers[A]);

	while (running) {
		eval(fetch());
		registers[INSTRUCTION_POINTER]++;

		print();
	}

	if (registers[A] != EXPECTED_RESULT) {
		printf("ERROR \n");
		return 1;
	} else {
		printf("SUCCESS \n");
		return 0;	
	}
}
