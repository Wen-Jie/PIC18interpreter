#include "unity.h"
#include "declaration.h"
#include "Literal_op.h"
#include "Control_op.h"
#include "byteOriented_op.h"
#include "bitOriented_op.h"

void setUp(void){}
void tearDown(void){}

void test_op_MOVLW_move_10101011_to_WREG(void)
{
	TEST_ASSERT_EQUAL(0b10101011, op_MOVLW(0b10101011));
}

void test_op_MOVLB_move_00000001_to_BSR(void)
{
    TEST_ASSERT_EQUAL(00000001, op_MOVLB(00000001));
}

void test_op_ADDLW_add_0x50_to_WREG_and_put_back_to_WREG(void)
{
    WREG = 0x20;
    TEST_ASSERT_EQUAL(WREG, op_ADDLW(0x50));
}

void test_op_ADDLW_add_0x40_to_WREG_and_put_back_to_WREG(void)
{
    WREG = 0x20;
    TEST_ASSERT_EQUAL(WREG, op_ADDLW(0x40));
}

void test_op_ANDLW_AND_0xAA_to_WREG_and_put_back_to_WREG(void)
{
    WREG = 0x10;
    TEST_ASSERT_EQUAL(WREG, op_ANDLW(0xAA));
}

void test_op_IORLW_inclusive_OR_0xBB_to_WREG_and_put_back_to_WREG(void)
{
    WREG = 0x10;
    TEST_ASSERT_EQUAL(WREG, op_IORLW(0xBB));
}

void test_op_MULLW_multiply_0xCC_to_WREG_and_put_back_to_WREG(void)
{
    WREG = 0x10;
    TEST_ASSERT_EQUAL(WREG, op_MULLW(0xCC));
}

void test_op_XORLW_exclusive_OR_0xDD_to_WREG_and_put_back_to_WREG(void)
{
    WREG = 0x10;
    TEST_ASSERT_EQUAL(WREG, op_XORLW(0xDD));
}