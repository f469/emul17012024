/**
 * Systems memory map :
 * 0x000-0x1FF - Chip 8 interpreter (contains font set in emu)
 * 0x050-0x0A0 - Used for the built in 4x5 pixel font set (0-F)
 * 0x200-0xFFF - Program ROM and work RAM
 */

// 35 opcodes each two bytes long
unsigned short opcode;

// 4K memory in total
unsigned char memory[4096];

//16 8-bit registers (V0,V1 up to VE). 16th register used for the carry flag
unsigned char V[16];

// Index register, value from 0x000 to 0xFFF
unsigned short I;

// Program counter, value from 0x000 to 0xFFF
unsigned short pc;

// Screen : 2048 pixels (64 x 32), black and white (1 or 0)
unsigned char gfx[64 * 32];

unsigned char delay_timer;
unsigned char sound_timer;

// Stack
unsigned short stack[16];
unsigned short sp;

// HEX based keypad (0x0-0xF)
unsigned char key[16];

int main() {
	return 0;
}
