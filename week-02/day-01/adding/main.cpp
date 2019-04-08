#include <iostream>

int main()
{
    // Add two numbers using pointers

    int a = 20;
    int b = 17;

    int *aPointer = &a;
    int *bPointer = &b;

    *aPointer += *bPointer;

    std::cout << *aPointer;

    return 0;
}