#include <iostream>

int main()
{
    // Create a program which accepts five integers from the console (given by the user)
    // and store them in an array
    // print out the values of that array using pointers again

    int array[5];
    std::cout << "Please give me 5 numbers!" << std::endl;
    int number;

    for (int i = 0; i < 5; ++i) {
        std::cin >> number;
        array[i] = number;
    }

    int *arrayPtr = array;

    std::cout << "The values of the array are: " << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << array[i] << std::endl;
    }

    std::cout << "The values of the array are: " << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << arrayPtr[i] << std::endl;
    }

    std::cout << "The values of the array are: " << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << *(array+i) << std::endl;
    }

    std::cout << "The values of the array are: " << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << *(arrayPtr + i) << std::endl;
    }

    return 0;
}
