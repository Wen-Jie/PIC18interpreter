#include "unity.h"
#include "declaration.h"
#include "byteOriented_op.h"
#include "Control_op.h"
#include "Literal_op.h"
#include "bitOriented_op.h"

void setUp(void){}
void tearDown(void){}

void test_op_MOVWF_move_11011110_to_00010010_file_register(void)
{
    WREG = 0b11011110;
	TEST_ASSERT_EQUAL(WREG, op_MOVWF(00010010));
}

void test_move_WREG_to_file_register(void)
{
    TEST_ASSERT_EQUAL(0b10101011, op_MOVLW(0b10101011));
	TEST_ASSERT_EQUAL(WREG, op_MOVWF(0));
}

void test_move_00010001_to_00010000_file_register_in_bank_1(void)
{
    op_MOVLB(0b00000001);
    op_MOVLW(0b00010001);
    TEST_ASSERT_EQUAL(WREG, op_MOVWF(0b00010000));
}

void test_move_0000000100000110_to_0x10_file_register_in_bank_6_should_return_0(void)
{
    op_MOVLB(0b0000000100000110);
    op_MOVLW(0b0000111000010001);
    TEST_ASSERT_EQUAL(0, op_MOVWF(0b0110111100010000));
}

void test_move_0x11_to_0x10_file_register_in_bank_5(void)
{
    op_MOVLB(0b0000000100000101);
    op_MOVLW(0b0000111000010001);
    TEST_ASSERT_EQUAL(WREG, op_MOVWF(0b0110111100010000));
}

void test_op_CLRF_clear_data_in_0x10_file_register(void)
{
    REG0[0x10] = 0x20;
    TEST_ASSERT_EQUAL(REG0[0x10], op_CLRF(0x010)); //the MSB 0 indicate default bank 
}

void test_op_CLRF_clear_data_in_bank_6_0x10_file_register_should_return_0(void)
{
    BSR = 0x06;
    REG4[0x10] = 0x20;
    TEST_ASSERT_EQUAL(0, op_CLRF(0x110)); //the MSB 1 indicate ACCESS bank
}

void test_op_CLRF_clear_data_in_bank_3_0x10_file_register(void)
{
    BSR = 0x03;
    REG3[0x10] = 0x20;
    TEST_ASSERT_EQUAL(REG3[0x10], op_CLRF(0x110)); //the MSB 1 indicate ACCESS bank 
}

void test_op_SETF_set_data_0x10_file_register(void)
{
    REG0[0x10] = 0x20;
    TEST_ASSERT_EQUAL(REG0[0x10], op_SETF(0x010)); //the MSB 0 indicate default bank 
}

void test_op_SETF_set_data_in_bank_4_0x10_file_register(void)
{
    BSR = 0x04;
    REG4[0x10] = 0x20;
    TEST_ASSERT_EQUAL(REG4[0x10], op_SETF(0x110)); //the MSB 1 indicate ACCESS bank 
}

void test_op_ADDWF_add_0x10_in_WREG_to_0x10_file_register_and_put_into_0x10_file_register(void)
{
    WREG = 0x10;
    REG0[0x10] = 0x20;
    TEST_ASSERT_EQUAL(REG0[0x10], op_ADDWF(0b0010011000010000)); //d = 1, a = 0, f = 0x10
}

void test_op_ADDWF_add_0x10_in_WREG_to_0x10_file_register_in_bank_3_and_put_into_0x10_file_register_in_bank_3(void)
{
    BSR = 0x03;
    WREG = 0x10;
    REG3[0x10] = 0x20;
    TEST_ASSERT_EQUAL(REG3[0x10], op_ADDWF(0b0010011100010000)); //d = 1, a = 1, f = 0x10
}

void test_op_ADDWF_add_0x10_in_WREG_to_0x10_file_register_and_put_back_WREG(void)
{
    WREG = 0x10;
    REG0[0x10] = 0x20;
    TEST_ASSERT_EQUAL(WREG, op_ADDWF(0b0010010000010000)); //d = 0, a = 0, f = 0x10
}

void test_op_ADDWF_add_0x10_in_WREG_to_0x10_file_register_in_bank_2_and_put_back_WREG(void)
{
    BSR = 0x02;
    WREG = 0x10;
    REG2[0x10] = 0x20;
    TEST_ASSERT_EQUAL(WREG, op_ADDWF(0b0010010100010000)); //d = 0, a = 1, f = 0x10
}

void test_op_ANDWF_AND_0x10_in_WREG_to_0x10_file_register_and_put_into_0x10_file_register(void)
{
    WREG = 0x10;
    REG0[0x10] = 0x20;
    TEST_ASSERT_EQUAL(REG0[0x10], op_ANDWF(0b0010011000010000)); //d = 1, a = 0, f = 0x10
}

void test_op_ANDWF_add_0x10_in_WREG_to_0x10_file_register_in_bank_3_and_put_into_0x10_file_register_in_bank_3(void)
{
    BSR = 0x03;
    WREG = 0x10;
    REG3[0x10] = 0x20;
    TEST_ASSERT_EQUAL(REG3[0x10], op_ANDWF(0b0010011100010000)); //d = 1, a = 1, f = 0x10
}

void test_op_ANDWF_add_0x10_in_WREG_to_0x10_file_register_and_put_back_WREG(void)
{
    WREG = 0x10;
    REG0[0x10] = 0x20;
    TEST_ASSERT_EQUAL(WREG, op_ANDWF(0b0010010000010000)); //d = 0, a = 0, f = 0x10
}

void test_op_ANDWF_add_0x10_in_WREG_to_0x10_file_register_in_bank_2_and_put_back_WREG(void)
{
    BSR = 0x02;
    WREG = 0x10;
    REG2[0x10] = 0x20;
    TEST_ASSERT_EQUAL(WREG, op_ANDWF(0b0010010100010000)); //d = 0, a = 1, f = 0x10
}

void test_op_COMF_complement_0x10_file_register_should_return_0xEC(void)
{
    REG0[0x10] = 0x13;
    TEST_ASSERT_EQUAL(0xEC, op_COMF(0b0001110000010000)); //d = 0, a = 0
}

void test_op_COMF_complement_0x10_file_register_in_bank_5_should_return_0xEC(void)
{
    BSR = 0x05;
    REG5[0x10] = 0x13;
    TEST_ASSERT_EQUAL(0xEC, op_COMF(0b0001110100010000)); //d = 0, a = 1
}

void test_op_COMF_complement_0x10_file_register_should_return_0xEC_and_put_back_to_0x10_file_register(void)
{
    REG0[0x10] = 0x13;
    TEST_ASSERT_EQUAL(0xEC, op_COMF(0b0001111000010000)); //d = 1, a = 0
}

void test_op_COMF_complement_0x10_file_register_in_bank_5_should_return_0xEC_and_put_back_to_0x10_file_register(void)
{
    BSR = 0x05;
    REG5[0x10] = 0x13;
    TEST_ASSERT_EQUAL(0xEC, op_COMF(0b0001111100010000)); //d = 1, a = 1
}

void test_op_DECF_decrement_0x10_file_register(void)
{
    REG0[0x10] = 0x34;
    TEST_ASSERT_EQUAL(0x33, op_DECF(0b0001111000010000)); //d = 1, a = 0
    TEST_ASSERT_EQUAL(REG0[0x10], op_DECF(0b0001111000010000)); //d = 1, a = 0
}

void test_op_DECF_decrement_0x10_file_register_in_bank_3(void)
{
    BSR = 0x03;
    REG3[0x10] = 0x34;
    TEST_ASSERT_EQUAL(0x33, op_DECF(0b0001111100010000)); //d = 1, a = 1
    TEST_ASSERT_EQUAL(REG3[0x10], op_DECF(0b0001111100010000)); //d = 1, a = 1
}

void test_op_DECF_decrement_0x10_file_register_in_bank_3_put_into_WREG(void)
{
    BSR = 0x03;
    REG3[0x10] = 0x34;
    TEST_ASSERT_EQUAL(0x33, op_DECF(0b0001110100010000)); //d = 0, a = 1
    TEST_ASSERT_EQUAL(WREG, op_DECF(0b0001110100010000)); //d = 0, a = 1
}

void test_op_DECF_decrement_0x10_file_register_put_into_WREG(void)
{
    BSR = 0x03;
    REG0[0x10] = 0x34;
    TEST_ASSERT_EQUAL(0x33, op_DECF(0b0001110100010000)); //d = 1, a = 0
    TEST_ASSERT_EQUAL(WREG, op_DECF(0b0001110100010000)); //d = 1, a = 0
}

void test_op_INCF_decrement_0x10_file_register(void)
{
    REG0[0x10] = 0x34;
    TEST_ASSERT_EQUAL(0x35, op_INCF(0b0001111000010000)); //d = 1, a = 0
    TEST_ASSERT_EQUAL(REG0[0x10], op_INCF(0b0001111000010000)); //d = 1, a = 0
}

void test_op_INCF_decrement_0x10_file_register_in_bank_3(void)
{
    BSR = 0x03;
    REG3[0x10] = 0x34;
    TEST_ASSERT_EQUAL(0x35, op_INCF(0b0001111100010000)); //d = 1, a = 1
    TEST_ASSERT_EQUAL(REG3[0x10], op_INCF(0b0001111100010000)); //d = 1, a = 1
}

void test_op_INCF_decrement_0x10_file_register_in_bank_3_put_into_WREG(void)
{
    BSR = 0x03;
    REG3[0x10] = 0x34;
    TEST_ASSERT_EQUAL(0x35, op_INCF(0b0001110100010000)); //d = 0, a = 1
    TEST_ASSERT_EQUAL(WREG, op_INCF(0b0001110100010000)); //d = 0, a = 1
}

void test_op_INCF_decrement_0x10_file_register_put_into_WREG(void)
{
    BSR = 0x03;
    REG0[0x10] = 0x34;
    TEST_ASSERT_EQUAL(0x35, op_INCF(0b0001110100010000)); //d = 1, a = 0
    TEST_ASSERT_EQUAL(WREG, op_INCF(0b0001110100010000)); //d = 1, a = 0
}