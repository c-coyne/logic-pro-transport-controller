#include "unity.h"

void setUp(void)
{
  // set stuff up here
}

void tearDown(void)
{
  // clean stuff up here
}

void basic_test_assert_equal(void) {
    TEST_ASSERT_EQUAL(32, 32);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(basic_test_assert_equal);
    return UNITY_END();
}