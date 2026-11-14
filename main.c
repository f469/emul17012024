#include "chip8.h"

int main() {
	initialize();

	// TODO : load the ROM here (path given as argument) into memory starting at 0x200.
	// Plan: a load_rom(path) function in chip8.c reading the file straight into memory
	// (no intermediate buffer), with errors for a missing file or a ROM that is too big.

	for(;;) {
		emulateCycle();
		break; // TODO : remove once ROM loading and a stop condition exist
	}
	return 0;
}
