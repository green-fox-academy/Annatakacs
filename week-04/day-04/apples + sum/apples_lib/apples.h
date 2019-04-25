//
// Created by Takacs Anna on 2019-04-25.
//

#ifndef APPLES_SUM_APPLES_H
#define APPLES_SUM_APPLES_H

#include <iostream>
#include <vector>

class Apples {
public:
    std::string getName();

    std::vector<int> numbers;

    int sumNumbers(std::vector<int> _numbers);
};


#endif //APPLES_SUM_APPLES_H
