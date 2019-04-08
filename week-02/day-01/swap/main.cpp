#include <iostream>

void swap(int *x, int *y);

int main ()
{
    // Create a function which swaps the values of 'a' and 'b'
    // This time use a void function and pointers

    int a = 10;
    int b = 316;

    int *aPointer = &a;
    int *bPointer = &b;

    std::cout << "The value of a before swap: " << *aPointer << std::endl;
    std::cout << "The value of b before swap: " << *bPointer << std::endl;

    swap(aPointer, bPointer);

    std::cout << "The value of a after swap: " << *aPointer << std::endl;
    std::cout << "The value of b after swap: " << *bPointer << std::endl;


    return 0;
}
void swap(int *x, int *y) {
    int temp = *y;
    *y = *x;
    *x = temp;
}