#ifndef declaration_H
#define declaration_H

#define Clear_1stByte                0b0000000011111111     //Clear first byte.
#define Bank_access_bit              0b0000000100000000     //Clear other bits except the access bit,if a equal to Bank_access_bit 
                                                            //means that RAM bank is specified by BSR register, otherwise BSR register is ignored.
#define Destination_select_bit       0b0000001000000000     //Clear other bits except the select bit,if d equal to Destination_select_bit
                                                            //means that result store in file register, otherwise store in WREG.
#define Bit_address                  0b0000111000000000     //Clear other bits except the bit address bbb.

int BSR;                     //Bank select register
int WREG;                    //Working register
int REG0[255];               //File registers in bank 0
int REG1[255];               //File registers in bank 1
int REG2[255];               //File registers in bank 2
int REG3[255];               //File registers in bank 3
int REG4[255];               //File registers in bank 4
int REG5[255];               //File registers in bank 5

#endif // declaration_H
