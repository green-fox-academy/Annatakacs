#include <iostream>
#include "Sharpie.h"

int main()
{
    Sharpie first ("red", 30.5);

    std::cout << first.getcolor() << " " << first.getwidth() << " " << first.getinkAmount() << std::endl;
    first.use();
    std::cout << first.getcolor() << " " << first.getwidth() << " " << first.getinkAmount() << std::endl;

    return 0;
}