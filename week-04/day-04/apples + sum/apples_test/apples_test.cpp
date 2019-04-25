//
// Created by Takacs Anna on 2019-04-25.
//

#include "gtest/gtest.h"
#include "apples.h"

TEST(TestApples, StringIsCorrect)
{

    Apples apples;

    ASSERT_EQ(apples.getName(), "apple");
}

TEST(TestSum, SumIsCorrect)
{
    Apples apples;

    std::vector<int> numbers = {1, 2, 3, 4, 5};

    ASSERT_EQ(apples.sumNumbers(numbers), 15);
}