#ifndef Literal_op_H
#define Literal_op_H

int op_MOVLW(int flash_Mem);
int op_MOVLB(int flash_Mem);
int op_MULLW(int flash_Mem);
int op_ADDLW(int flash_Mem);
int op_ANDLW(int flash_Mem);
int op_IORLW(int flash_Mem);
int op_XORLW(int flash_Mem);

#endif // Literal_op_H
