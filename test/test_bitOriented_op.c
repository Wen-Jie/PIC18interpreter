#include "unity.h"
#include "declaration.h"
#include "bitOriented_op.h"
#include "Control_op.h"
#include "Literal_op.h"
#include "byteOriented_op.h"

void setUp(void){}
void tearDown(void){}


void test_op_BCF_clear_bit_0_of_0x10_file_regiter(void)
{
    REG0[0x10] = 0b00011101;
    TEST_ASSERT_EQUAL(0b00011100, op_BCF(0b1001000000010000)); //bbb = 000, a = 0
}

void test_op_BCF_clear_bit_0_of_0x11_file_regiter(void)
{
    REG0[0x11] = 0b00011111;
    TEST_ASSERT_EQUAL(0b00011101, op_BCF(0b1001001000010001)); //bbb = 001, a = 0
}

void test_op_BCF_clear_bit_0_of_0x11_file_regiter_in_bank_1(void)
{
    BSR = 0x01;
    REG1[0x11] = 0b00011111;
    TEST_ASSERT_EQUAL(0b00011101, op_BCF(0b1001001100010001)); //bbb = 001, a = 1
}

void test_op_BCF_clear_bit_0_of_0x11_file_regiter_in_bank_5(void)
{
    BSR = 0x05;
    REG5[0x11] = 0b00011111;
    TEST_ASSERT_EQUAL(0b00011101, op_BCF(0b1001001100010001)); //bbb = 001, a = 1
}

void test_op_BSF_set_bit_0_of_0x10_file_regiter(void)
{
    REG0[0x10] = 0b00011100;
    TEST_ASSERT_EQUAL(0b00011101, op_BSF(0b1001000000010000)); //bbb = 000, a = 0
}

void test_op_BSF_set_bit_0_of_0x11_file_regiter(void)
{
    REG0[0x11] = 0b00011101;
    TEST_ASSERT_EQUAL(0b00011111, op_BSF(0b1001001000010001)); //bbb = 001, a = 0
}

void test_op_BSF_clear_bit_0_of_0x11_file_regiter_in_bank_1(void)
{
    BSR = 0x01;
    REG1[0x11] = 0b00011101;
    TEST_ASSERT_EQUAL(0b00011111, op_BSF(0b1001001100010001)); //bbb = 001, a = 1
}

void test_op_BSF_clear_bit_0_of_0x11_file_regiter_in_bank_5(void)
{
    BSR = 0x05;
    REG5[0x11] = 0b00011101;
    TEST_ASSERT_EQUAL(0b00011111, op_BSF(0b1001001100010001)); //bbb = 001, a = 1
}
