#include "declaration.h"
#include "bitOriented_op.h"
#include "byteOriented_op.h"
#include "Control_op.h"
#include "Literal_op.h"

//Bit clear file register
int op_BCF(int flash_Mem)
{
    int loc = flash_Mem & Clear_1stByte;
    int a = flash_Mem & Bank_access_bit;
    int bbb = flash_Mem & Bit_address;
    
    if(a == Bank_access_bit)
    {
        switch(BSR)
        {
            case 1: switch(bbb)
            {
                case 0x000: return REG1[loc] &= 0b11111110;
                case 0x200: return REG1[loc] &= 0b11111101;
                case 0x400: return REG1[loc] &= 0b11111011;
                case 0x600: return REG1[loc] &= 0b11110111;
                case 0x800: return REG1[loc] &= 0b11101111;
                case 0xA00: return REG1[loc] &= 0b11011111;
                case 0xC00: return REG1[loc] &= 0b10111111;
                case 0xE00: return REG1[loc] &= 0b01111111;
                default : op_NOP();
            }
            case 2: switch(bbb)
            {
                case 0x000: return REG2[loc] &= 0b11111110;
                case 0x200: return REG2[loc] &= 0b11111101;
                case 0x400: return REG2[loc] &= 0b11111011;
                case 0x600: return REG2[loc] &= 0b11110111;
                case 0x800: return REG2[loc] &= 0b11101111;
                case 0xA00: return REG2[loc] &= 0b11011111;
                case 0xC00: return REG2[loc] &= 0b10111111;
                case 0xE00: return REG2[loc] &= 0b01111111;
                default : op_NOP();
            }
            case 3: switch(bbb)
            {
                case 0x000: return REG3[loc] &= 0b11111110;
                case 0x200: return REG3[loc] &= 0b11111101;
                case 0x400: return REG3[loc] &= 0b11111011;
                case 0x600: return REG3[loc] &= 0b11110111;
                case 0x800: return REG3[loc] &= 0b11101111;
                case 0xA00: return REG3[loc] &= 0b11011111;
                case 0xC00: return REG3[loc] &= 0b10111111;
                case 0xE00: return REG3[loc] &= 0b01111111;
                default : op_NOP();
            }
            case 4: switch(bbb)
            {
                case 0x000: return REG4[loc] &= 0b11111110;
                case 0x200: return REG4[loc] &= 0b11111101;
                case 0x400: return REG4[loc] &= 0b11111011;
                case 0x600: return REG4[loc] &= 0b11110111;
                case 0x800: return REG4[loc] &= 0b11101111;
                case 0xA00: return REG4[loc] &= 0b11011111;
                case 0xC00: return REG4[loc] &= 0b10111111;
                case 0xE00: return REG4[loc] &= 0b01111111;
                default : op_NOP();
            }
            case 5: switch(bbb)
            {
                case 0x000: return REG5[loc] &= 0b11111110;
                case 0x200: return REG5[loc] &= 0b11111101;
                case 0x400: return REG5[loc] &= 0b11111011;
                case 0x600: return REG5[loc] &= 0b11110111;
                case 0x800: return REG5[loc] &= 0b11101111;
                case 0xA00: return REG5[loc] &= 0b11011111;
                case 0xC00: return REG5[loc] &= 0b10111111;
                case 0xE00: return REG5[loc] &= 0b01111111;
                default : op_NOP();
            }
            default : op_NOP;
        }
    }
    else
    {
        switch(bbb)
        {
            case 0x000: return REG0[loc] &= 0b11111110;
            case 0x200: return REG0[loc] &= 0b11111101;
            case 0x400: return REG0[loc] &= 0b11111011;
            case 0x600: return REG0[loc] &= 0b11110111;
            case 0x800: return REG0[loc] &= 0b11101111;
            case 0xA00: return REG0[loc] &= 0b11011111;
            case 0xC00: return REG0[loc] &= 0b10111111;
            case 0xE00: return REG0[loc] &= 0b01111111;
            default : op_NOP();
        }
    }
}

//Bit set file register
int op_BSF(int flash_Mem)
{
    int loc = flash_Mem & Clear_1stByte;
    int a = flash_Mem & Bank_access_bit;
    int bbb = flash_Mem & Bit_address;
    
    if(a == Bank_access_bit)
    {
        switch(BSR)
        {
            case 1: switch(bbb)
            {
                case 0x000: return REG1[loc] |= 0b00000001;
                case 0x200: return REG1[loc] |= 0b00000010;
                case 0x400: return REG1[loc] |= 0b00000100;
                case 0x600: return REG1[loc] |= 0b00001000;
                case 0x800: return REG1[loc] |= 0b00010000;
                case 0xA00: return REG1[loc] |= 0b00100000;
                case 0xC00: return REG1[loc] |= 0b01000000;
                case 0xE00: return REG1[loc] |= 0b10000000;
                default : op_NOP();
            }
            case 2: switch(bbb)
            {
                case 0x000: return REG2[loc] |= 0b00000001;
                case 0x200: return REG2[loc] |= 0b00000010;
                case 0x400: return REG2[loc] |= 0b00000100;
                case 0x600: return REG2[loc] |= 0b00001000;
                case 0x800: return REG2[loc] |= 0b00010000;
                case 0xA00: return REG2[loc] |= 0b00100000;
                case 0xC00: return REG2[loc] |= 0b01000000;
                case 0xE00: return REG2[loc] |= 0b10000000;
                default : op_NOP();
            }
            case 3: switch(bbb)
            {
                case 0x000: return REG3[loc] |= 0b00000001;
                case 0x200: return REG3[loc] |= 0b00000010;
                case 0x400: return REG3[loc] |= 0b00000100;
                case 0x600: return REG3[loc] |= 0b00001000;
                case 0x800: return REG3[loc] |= 0b00010000;
                case 0xA00: return REG3[loc] |= 0b00100000;
                case 0xC00: return REG3[loc] |= 0b01000000;
                case 0xE00: return REG3[loc] |= 0b10000000;
                default : op_NOP();
            }
            case 4: switch(bbb)
            {
                case 0x000: return REG4[loc] |= 0b00000001;
                case 0x200: return REG4[loc] |= 0b00000010;
                case 0x400: return REG4[loc] |= 0b00000100;
                case 0x600: return REG4[loc] |= 0b00001000;
                case 0x800: return REG4[loc] |= 0b00010000;
                case 0xA00: return REG4[loc] |= 0b00100000;
                case 0xC00: return REG4[loc] |= 0b01000000;
                case 0xE00: return REG4[loc] |= 0b10000000;
                default : op_NOP();
            }
            case 5: switch(bbb)
            {
                case 0x000: return REG5[loc] |= 0b00000001;
                case 0x200: return REG5[loc] |= 0b00000010;
                case 0x400: return REG5[loc] |= 0b00000100;
                case 0x600: return REG5[loc] |= 0b00001000;
                case 0x800: return REG5[loc] |= 0b00010000;
                case 0xA00: return REG5[loc] |= 0b00100000;
                case 0xC00: return REG5[loc] |= 0b01000000;
                case 0xE00: return REG5[loc] |= 0b10000000;
                default : op_NOP();
            }
            default : op_NOP;
        }
    }
    else
    {
        switch(bbb)
        {
                case 0x000: return REG0[loc] |= 0b00000001;
                case 0x200: return REG0[loc] |= 0b00000010;
                case 0x400: return REG0[loc] |= 0b00000100;
                case 0x600: return REG0[loc] |= 0b00001000;
                case 0x800: return REG0[loc] |= 0b00010000;
                case 0xA00: return REG0[loc] |= 0b00100000;
                case 0xC00: return REG0[loc] |= 0b01000000;
                case 0xE00: return REG0[loc] |= 0b10000000;
                default : op_NOP();
        }
    }
}