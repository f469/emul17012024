#include "chip8.h"

int main() {
	initialize();

	for(int i = 0; i < bufferSize; ++i)
  	memory[i + 512] = buffer[i];

	for(;;) {
		emulateCycle();
	}
	return 0;
}
