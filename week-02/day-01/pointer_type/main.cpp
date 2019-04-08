#include <iostream>

int main ()
{
    // Create a pointer for each variable and print out the memory addresses of that variables
    // Print out the values of the pointers

    int a = 31;
    double b = 432.2;
    std::string name = "Bob";

    int *aPointer = &a;
    double *bPointer = &b;
    std::string *namePointer = &name;

    std::cout << "Memory address of a; " << aPointer << std::endl;
    std::cout << "Memory address of b; " << bPointer << std::endl;
    std::cout << "Memory address of name; " << namePointer << std::endl;

    std::cout << "Value of a; " << *aPointer << std::endl;
    std::cout << "Value of b; " << *bPointer << std::endl;
    std::cout << "Value of name; " << *namePointer << std::endl;



    return 0;
}