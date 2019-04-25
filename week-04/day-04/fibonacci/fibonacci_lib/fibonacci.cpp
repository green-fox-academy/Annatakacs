//
// Created by Takacs Anna on 2019-04-25.
//

#include "fibonacci.h"

int Fibonacci::countFibonacci(int index)
{
    if (index == 0 || index == 1 || index == 2) {
        return index;
    } else {
        return countFibonacci(index-1) + countFibonacci(index - 2);
    }
}