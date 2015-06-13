#include "declaration.h"
#include "Literal_op.h"
#include "bitOriented_op.h"
#include "byteOriented_op.h"
#include "Control_op.h"

//Add literal and WREG
int op_ADDLW(int flash_Mem)
{
    flash_Mem &= Clear_1stByte;
    WREG += flash_Mem;
    return WREG;
}

//AND literal with WREG
int op_ANDLW(int flash_Mem)
{
    flash_Mem &= Clear_1stByte;
    WREG &= flash_Mem;
    return WREG;
}

//Inclusive OR literal with WREG
int op_IORLW(int flash_Mem)
{
    flash_Mem &= Clear_1stByte;
    WREG |= flash_Mem;
    return WREG;
}

//Exclusive OR literal with WREG
int op_XORLW(int flash_Mem)
{
    flash_Mem &= Clear_1stByte;
    WREG = ~(WREG | flash_Mem);
    return WREG;
}

//Move literal to WREG
int op_MOVLW(int flash_Mem)
{
    WREG = flash_Mem & Clear_1stByte;
    return WREG;
}

//Move literal to BSR<3:0>
int op_MOVLB(int flash_Mem)
{
    int MSB_12bits = 0b0000000000001111;
    BSR = flash_Mem & MSB_12bits;
    return BSR;
}

//Multiply literal with WREG
int op_MULLW(int flash_Mem)
{
    flash_Mem &= Clear_1stByte;
    WREG *= flash_Mem;
    return WREG;
}
