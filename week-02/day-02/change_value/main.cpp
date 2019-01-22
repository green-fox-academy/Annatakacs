#include <iostream>

int main ()
{
    // Change the value of the variable called 'temperature' using a pointer
    // (you have to create the pointer first)

    float temperature = 21.3;
    float *p_temperature;
    p_temperature = &temperature;

    //std::cout << p_temperature << std::endl;
    //std::cout << *p_temperature << std::endl;

    *p_temperature = 25.6;
    std::cout << *p_temperature << std::endl;
    //std::cout << p_temperature << std::endl;

    return 0;
}