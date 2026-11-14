#include "chip8.h"

int main() {
	initialize();

	for(;;) {
		emulateCycle();
		break; // TODO : remove once ROM loading and a stop condition exist
	}
	return 0;
}
