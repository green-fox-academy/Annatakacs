#include <iostream>

int valueFinder(int *array, int size, int value);

int main() {
    // Create a function which takes an array (and it's length) and a number as a parameter
    // the function should return index where it found the given value
    // if it can't find the number return -1

    std::cout << "How many numbers would you like to take?" << std::endl;
    int size;
    std::cin >> size;

    std::cout << "Please give me " << size << " numbers! " << std::endl;
    int array[size];
    int number;
    for (int i = 0; i < size; ++i) {
        std::cin >> number;
        array[i] = number;
    }

    std::cout << "Please give me one of the above mentioned numbers" << std::endl;
    int value;
    std::cin >> value;

    std::cout << "The index of the given value is: " << valueFinder(array, size, value);

    return 0;
}

int valueFinder(int *array, int size, int value) {
    for (int i = 0; i < size; ++i) {
        if (value == *(array+i)) {
            return i;
        }
    } return -1;
}
