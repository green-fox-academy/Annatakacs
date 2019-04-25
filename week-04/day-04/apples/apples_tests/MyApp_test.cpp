#include "gtest/gtest.h"
#include "MyClass.h"

TEST(TestApples, TestIfOutputIsValid)
{
    ASSERT_EQ(getApple(), "apple");
}