#include "chip8.h"

// State definitions (declared extern in chip8.h)
unsigned short opcode;
unsigned char memory[4096];
unsigned char V[16];
unsigned short I;
unsigned short pc;
unsigned char gfx[64 * 32];
unsigned char delay_timer;
unsigned char sound_timer;
unsigned short stack[16];
unsigned short sp;
unsigned char key[16];

void initialize()
{
  pc     = 0x200;  // Program counter starts at 0x200
  opcode = 0;      // Reset current opcode	
  I      = 0;      // Reset index register
  sp     = 0;      // Reset stack pointer
 
  // Clear display	
  // Clear stack
  // Clear registers V0-VF
  // Clear memory
 
  // Load fontset
  for(int i = 0; i < 80; ++i)
    memory[i] = chip8_fontset[i];		
 
  // Reset timers
}

void emulateCycle()
{
  // Fetch opcode
  opcode = memory[pc] << 8 | memory[pc + 1];
 
  // Decode opcode
  switch(opcode & 0xF000)
  {    
    // Some opcodes //
 
    case 0xA000: // ANNN: Sets I to the address NNN
      // Execute opcode
      I = opcode & 0x0FFF;
      pc += 2;
    break;
 
    // More opcodes //
 
    default:
      printf ("Unknown opcode: 0x%X\n", opcode);
  }  
 
  // Update timers
  if(delay_timer > 0)
    --delay_timer;
 
  if(sound_timer > 0)
  {
    if(sound_timer == 1)
      printf("BEEP!\n");
    --sound_timer;
  }  
}