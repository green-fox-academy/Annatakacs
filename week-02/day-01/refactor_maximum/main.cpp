#include <iostream>

int sizeFunction(int *x);

int *arrayFunction(int array[], int size);

void printBiggest(int *array, int size);

int main() {
    // Refactor time!
    // use your 'refactor_maximum.cpp', solve the same exercise by creating a separate function
    // for each functionality

    // Create a program which first asks for a number
    // this number indicates how many integers we want to store in an array
    // and than asks for numbers till the user fills the array
    // It should print out the biggest number in the given array and the memory address of it


    int size;
    sizeFunction(&size);

    int array[size];

    int *arrayPtr = arrayFunction(array, size);

    for (int i = 0; i < size; ++i) {
        std::cout << *(arrayPtr + i) << std::endl;
    }


    printBiggest(arrayPtr, size);

    return 0;
}

int sizeFunction(int *x) {
    std::cout << "How many numbers would you like to take?" << std::endl;
    std::cin >> *x;
    return *x;
}

int *arrayFunction(int array[], int size) {
    std::cout << "Please give me " << size << " numbers! " << std::endl;
    int number;
    for (int i = 0; i < size; ++i) {
        std::cin >> number;
        array[i] = number;
    }
    return array;
}

void printBiggest(int array[], int size) {
    int *ptr = array;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < (size - 1); ++j) {
            if (array[j] < array[j+1]) {
                *ptr = array[j+1];
            }
        }
    }
    std::cout << "The biggest number of the given array is: " << *ptr << std::endl;
    std::cout << "The memory address of the biggest number of the given array is: " << ptr << std::endl;

}