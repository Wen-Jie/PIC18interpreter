#include "unity.h"
#include "declaration.h"
#include "Control_op.h"
#include "Literal_op.h"
#include "byteOriented_op.h"
#include "bitOriented_op.h"

void setUp(void){}
void tearDown(void){}

void test_op_NOP_should_return_0(void)
{
    TEST_ASSERT_EQUAL(0, op_NOP());
}
