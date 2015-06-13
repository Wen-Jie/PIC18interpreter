#include "declaration.h"
#include "byteOriented_op.h"
#include "bitOriented_op.h"
#include "Control_op.h"
#include "Literal_op.h"

//Add WREG and file register
int op_ADDWF(int flash_Mem)
{
    int loc = flash_Mem & Clear_1stByte;
    int d = flash_Mem & Destination_select_bit;
    int a = flash_Mem & Bank_access_bit;
    
    if(d == Destination_select_bit)
    {
        if(a == Bank_access_bit)
        {
            switch(BSR)
            {
                case 1 : REG1[loc] += WREG; return REG1[loc];
                case 2 : REG2[loc] += WREG; return REG2[loc];
                case 3 : REG3[loc] += WREG; return REG3[loc];
                case 4 : REG4[loc] += WREG; return REG4[loc];
                case 5 : REG5[loc] += WREG; return REG5[loc];
                default : op_NOP();
            }
        }
        else
        {
            REG0[loc] += WREG; 
            return REG0[loc];
        }
    }
    else
    {
        if(a == Bank_access_bit)
        {
            switch(BSR)
            {
                case 1 : WREG += REG1[loc]; return WREG;
                case 2 : WREG += REG2[loc]; return WREG;
                case 3 : WREG += REG3[loc]; return WREG;
                case 4 : WREG += REG4[loc]; return WREG;
                case 5 : WREG += REG5[loc]; return WREG;
                default : op_NOP();
            }
        }
        else
        {
            WREG += REG0[loc];
            return WREG;
        }        
    }
}

//AND WREG with file register
int op_ANDWF(int flash_Mem)
{
    int loc = flash_Mem & Clear_1stByte;
    int d = flash_Mem & Destination_select_bit;
    int a = flash_Mem & Bank_access_bit;
    
    if(d == Destination_select_bit)
    {
        if(a == Bank_access_bit)
        {
            switch(BSR)
            {
                case 1 : REG1[loc] &= WREG; return REG1[loc];
                case 2 : REG2[loc] &= WREG; return REG2[loc];
                case 3 : REG3[loc] &= WREG; return REG3[loc];
                case 4 : REG4[loc] &= WREG; return REG4[loc];
                case 5 : REG5[loc] &= WREG; return REG5[loc];
                default : op_NOP();
            }
        }
        else
        {
            REG0[loc] &= WREG; 
            return REG0[loc];
        }
    }
    else
    {
        if(a == Bank_access_bit)
        {
            switch(BSR)
            {
                case 1 : WREG &= REG1[loc]; return WREG;
                case 2 : WREG &= REG2[loc]; return WREG;
                case 3 : WREG &= REG3[loc]; return WREG;
                case 4 : WREG &= REG4[loc]; return WREG;
                case 5 : WREG &= REG5[loc]; return WREG;
                default : op_NOP();
            }
        }
        else
        {
            WREG &= REG0[loc];
            return WREG;
        }        
    }
}

//Complement file register
int op_COMF(int flash_Mem)
{
    int loc = flash_Mem & Clear_1stByte;
    int d = flash_Mem & Destination_select_bit;
    int a = flash_Mem & Bank_access_bit;
    int temp;
    
    if(d == Destination_select_bit)
    {
        if(a == Bank_access_bit)
        {
            switch(BSR)
            {
                case 1 : temp = REG1[loc]; 
                         temp |= 0b11111111111111111111111100000000;
                         REG1[loc] = ~temp;
                         return REG1[loc]; 
                case 2 : temp = REG2[loc]; 
                         temp |= 0b11111111111111111111111100000000;
                         REG2[loc] = ~temp;
                         return REG2[loc]; 
                case 3 : temp = REG3[loc]; 
                         temp |= 0b11111111111111111111111100000000;
                         REG3[loc] = ~temp;
                         return REG3[loc]; 
                case 4 : temp = REG4[loc]; 
                         temp |= 0b11111111111111111111111100000000;
                         REG4[loc] = ~temp;
                         return REG4[loc]; 
                case 5 : temp = REG5[loc]; 
                         temp |= 0b11111111111111111111111100000000;
                         REG5[loc] = ~temp;
                         return REG5[loc]; 
                default : op_NOP();
            }
        }
        else
        {
           temp = REG0[loc];
           temp |= 0b11111111111111111111111100000000;
           REG0[loc] = ~temp;
           return REG0[loc];
        }
    }
    else
    {
        if(a == Bank_access_bit)
        {
            switch(BSR)
            {
                case 1 : temp = REG1[loc]; 
                         temp |= 0b11111111111111111111111100000000;
                         WREG = ~temp;
                         return WREG; 
                case 2 : temp = REG2[loc]; 
                         temp |= 0b11111111111111111111111100000000;
                         WREG = ~temp;
                         return WREG; 
                case 3 : temp = REG3[loc]; 
                         temp |= 0b11111111111111111111111100000000;
                         WREG = ~temp;
                         return WREG; 
                case 4 : temp = REG4[loc]; 
                         temp |= 0b11111111111111111111111100000000;
                         WREG = ~temp;
                         return WREG; 
                case 5 : temp = REG5[loc]; 
                         temp |= 0b11111111111111111111111100000000;
                         WREG = ~temp;
                         return WREG; 
                default : op_NOP();
            }
        }
        else
        {
           temp = REG0[loc];
           temp |= 0b11111111111111111111111100000000;
           WREG = ~temp;
           return WREG;
        }
    }
}

//Decrement file register
int op_DECF(int flash_Mem)
{
    int loc = flash_Mem & Clear_1stByte;
    int d = flash_Mem & Destination_select_bit;
    int a = flash_Mem & Bank_access_bit;
    
    if(d == Destination_select_bit)
    {
        if(a == Bank_access_bit)
        {
            switch(BSR)
            {
                case 1: REG1[loc] -= 1; return REG1[loc];
                case 2: REG2[loc] -= 1; return REG2[loc];
                case 3: REG3[loc] -= 1; return REG3[loc];
                case 4: REG4[loc] -= 1; return REG4[loc];
                case 5: REG5[loc] -= 1; return REG5[loc];
                default: op_NOP();
            }
        }
        else
        {
            REG0[loc] -= 1;
            return REG0[loc];
        }
    }
    else
    {
        if(a == Bank_access_bit)
        {
            switch(BSR)
            {
                case 1: WREG = REG1[loc] - 1; return WREG;
                case 2: WREG = REG2[loc] - 1; return WREG;
                case 3: WREG = REG3[loc] - 1; return WREG;
                case 4: WREG = REG4[loc] - 1; return WREG;
                case 5: WREG = REG5[loc] - 1; return WREG;
                default: op_NOP();
            }
        }
        else
        {
             WREG = REG0[loc] - 1;
             return WREG;
        }
    }
}

//Increment file register
int op_INCF(int flash_Mem)
{
    int loc = flash_Mem & Clear_1stByte;
    int d = flash_Mem & Destination_select_bit;
    int a = flash_Mem & Bank_access_bit;
    
    if(d == Destination_select_bit)
    {
        if(a == Bank_access_bit)
        {
            switch(BSR)
            {
                case 1: REG1[loc] += 1; return REG1[loc];
                case 2: REG2[loc] += 1; return REG2[loc];
                case 3: REG3[loc] += 1; return REG3[loc];
                case 4: REG4[loc] += 1; return REG4[loc];
                case 5: REG5[loc] += 1; return REG5[loc];
                default: op_NOP();
            }
        }
        else
        {
            REG0[loc] += 1;
            return REG0[loc];
        }
    }
    else
    {
        if(a == Bank_access_bit)
        {
            switch(BSR)
            {
                case 1: WREG = REG1[loc] + 1; return WREG;
                case 2: WREG = REG2[loc] + 1; return WREG;
                case 3: WREG = REG3[loc] + 1; return WREG;
                case 4: WREG = REG4[loc] + 1; return WREG;
                case 5: WREG = REG5[loc] + 1; return WREG;
                default: op_NOP();
            }
        }
        else
        {
             WREG = REG0[loc] + 1;
             return WREG;
        }
    }
}

//Clear file register
int op_CLRF(int flash_Mem)
{
    int loc = flash_Mem & Clear_1stByte;
    int a = flash_Mem & Bank_access_bit;
    
    if(a == Bank_access_bit)
    {
        switch(BSR)
        {
            case 1 : REG1[loc] = 0; return REG1[loc];
            case 2 : REG2[loc] = 0; return REG2[loc];
            case 3 : REG3[loc] = 0; return REG3[loc];
            case 4 : REG4[loc] = 0; return REG4[loc];
            case 5 : REG5[loc] = 0; return REG5[loc];
            default : op_NOP();
        }
    }
    else
    {
        REG0[loc] = 0;
        return REG0[loc];
    }
}

//Set file register
int op_SETF(int flash_Mem)
{
    int loc = flash_Mem & Clear_1stByte;
    int a = flash_Mem & Bank_access_bit;
    
    if(a == Bank_access_bit)
    {
        switch(BSR)
        {
            case 1 : REG1[loc] = 0xFF; return REG1[loc];
            case 2 : REG2[loc] = 0xFF; return REG2[loc];
            case 3 : REG3[loc] = 0xFF; return REG3[loc];
            case 4 : REG4[loc] = 0xFF; return REG4[loc];
            case 5 : REG5[loc] = 0xFF; return REG5[loc];
            default : op_NOP();
        }
    }
    else
    {
        REG0[loc] = 0xFF;
        return REG0[loc];
    }
}

//Move WREG to file register
int op_MOVWF(int flash_Mem)
{
    int loc = flash_Mem & Clear_1stByte;
    int a = flash_Mem & Bank_access_bit;
    
    if(a == Bank_access_bit)
    {
        switch(BSR)
        {
            case 1 : REG1[loc] = WREG; return REG1[loc];
            case 2 : REG2[loc] = WREG; return REG2[loc];
            case 3 : REG3[loc] = WREG; return REG3[loc];
            case 4 : REG4[loc] = WREG; return REG4[loc];
            case 5 : REG5[loc] = WREG; return REG5[loc];
            default : op_NOP();
        }
    }
    else
    {
        REG0[loc] = WREG;
        return REG0[loc];
    }
}

