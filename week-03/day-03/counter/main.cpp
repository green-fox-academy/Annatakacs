#include <iostream>
#include "Counter.h"

int main()
{
    Counter randomnumber(30);

    std::cout << randomnumber.get() << std::endl;
    randomnumber.add();
    std::cout << randomnumber.get() << std::endl;
    randomnumber.add(20);
    std::cout << randomnumber.get() << std::endl;
    randomnumber.reset();
    std::cout << randomnumber.get() << std::endl;

    return 0;
}