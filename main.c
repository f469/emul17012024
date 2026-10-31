#include <stdio.h>
#include <stdbool.h>

typedef enum {
   A, INSTRUCTION_POINTER, STACK_POINTER,
   NUM_OF_REGISTERS
} Registers;

int registers[NUM_OF_REGISTERS];
bool running = true;

int main(int argc, char *argv[]) {
	return 0;
}
