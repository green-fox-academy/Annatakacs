#include <iostream>

int main()
{
    // Create a program which accepts five integers from the console (given by the user)
    // and store them in an array
    // print out the memory addresses of the elements in the array

    int array[5];
    std::cout << "Please tell me 5 numbers!" << std::endl;
    int number;
    for (int i = 0; i < 5; ++i) {
        std::cin >> number;
        number = array[i];
    }

    int *arrayPtr = array;

    std::cout << "The memory addresses of the elements are: " << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << (array + i) << std::endl;
    }

    std::cout << "The memory addresses of the elements are: " << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << (arrayPtr + i) << std::endl;
    }

    return 0;
}
