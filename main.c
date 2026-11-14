#include "chip8.h"

int main() {
	initialize();

	// TODO : load the program into the memory, after initialization:
	//  - open the ROM with fopen in binary mode ("rb") and read it into a buffer (bufferSize bytes)
	//  - fill the memory starting at 0x200 (== 512):
	//      for(int i = 0; i < bufferSize; ++i)
	//        memory[i + 512] = buffer[i];
	//  - to improve later: check that bufferSize fits (4096 - 512) before copying

	for(;;) {
		emulateCycle();
		break; // TODO : remove once ROM loading and a stop condition exist
	}
	return 0;
}
