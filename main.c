#include <stdio.h>
#include <stdbool.h>

typedef enum {
   A, INSTRUCTION_POINTER, STACK_POINTER,
   NUM_OF_REGISTERS
} Registers;

int registers[NUM_OF_REGISTERS];
bool running = true;

void print() {
	printf("\n EOC \n");
	printf("SP : %i \n", registers[STACK_POINTER]);
	printf("IP : %i \n", registers[INSTRUCTION_POINTER]);
	printf("A register : %i \n\n", registers[A]);
}

int main(int argc, char *argv[]) {
	printf("\n FC \n");
	printf("SP : %i \n", registers[STACK_POINTER]);
	printf("IP : %i \n", registers[INSTRUCTION_POINTER]);
	printf("A register : %i \n\n", registers[A]);
	return 0;
}
