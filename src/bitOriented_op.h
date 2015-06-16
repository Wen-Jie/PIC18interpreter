#ifndef bitOriented_op_H
#define bitOriented_op_H

#define Bit_address     0b0000111000000000     //Clear other bits except the bit address bbb.
#define bit0            0b00000001             //Use to test bit 0 in file register for toggling.       
#define bit1            0b00000010             //Use to test bit 1 in file register for toggling. 
#define bit2            0b00000100             //Use to test bit 2 in file register for toggling. 
#define bit3            0b00001000             //Use to test bit 3 in file register for toggling. 
#define bit4            0b00010000             //Use to test bit 4 in file register for toggling. 
#define bit5            0b00100000             //Use to test bit 5 in file register for toggling. 
#define bit6            0b01000000             //Use to test bit 6 in file register for toggling. 
#define bit7            0b10000000             //Use to test bit 7 in file register for toggling.                  

int op_BCF(int flash_Mem);
int op_BSF(int flash_Mem);

#endif // bitOriented_op_H
