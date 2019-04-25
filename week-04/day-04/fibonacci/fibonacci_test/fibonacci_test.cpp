#include "gtest/gtest.h"
#include "fibonacci.h"

TEST(TestFibonacci, SeeFibonacci10Index)
{
    // Arrange
    Fibonacci fibonacci;
    int index = 10;

    // Act
    int result = fibonacci.countFibonacci(index);

    // Assert
    ASSERT_EQ(result, 89);
}

TEST(TestFibonacci, SeeFibonacci0Index)
{
    // Arrange
    Fibonacci fibonacci;
    int index = 0;

    // Act
    int result = fibonacci.countFibonacci(index);

    // Assert
    ASSERT_EQ(result, 0);
}

TEST(TestFibonacci, SeeFibonacci5Index)
{
    // Arrange
    Fibonacci fibonacci;
    int index = 5;

    // Act
    int result = fibonacci.countFibonacci(index);

    // Assert
    ASSERT_EQ(result, 8);
}