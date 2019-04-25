//
// Created by Takacs Anna on 2019-04-25.
//

#include "apples.h"

std::string Apples::getName()
{
    return "apple";
}

int Apples::sumNumbers(std::vector<int> numbers)
{
    int sum = 0;
    for (unsigned int i = 0; i < numbers.size(); ++i) {
        sum += numbers.at(i);
    }
    return sum;
}