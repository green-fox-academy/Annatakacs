#include <iostream>

int main ()
{
    // Create a pointer for each variable and print out the memory addresses of that variables
    // Print out the values of the pointers

    int a = 31;
    int *p_a = &a;

    double b = 432.2;
    double *p_b = &b;

    std::string name = "Bob";
    std::string *p_name = &name;

    std::cout << "Address of int: " << p_a << std::endl;
    std::cout << "Address of double: " << p_b << std::endl;
    std::cout << "Address of string: " << p_name << std::endl;

    std::cout << "Address of int: " << *p_a << std::endl;
    std::cout << "Address of double: " << *p_b << std::endl;
    std::cout << "Address of string: " << *p_name << std::endl;



    return 0;
}