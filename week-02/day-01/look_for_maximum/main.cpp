#include <iostream>

void printBiggest(int array[], int size);

int main()
{
    // Create a program which first asks for a number
    // this number indicates how many integers we want to store in an array
    // and than asks for numbers till the user fills the array
    // It should print out the biggest number in the given array and the memory address of it

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


    printBiggest(array, size);

    return 0;
}
void printBiggest(int array[], int size) {
    int *ptr = array;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < (size-1); ++j) {
            if (array[j] < array[j+1]) {
                *ptr = array[j+1];
            }
        }
    }
    std::cout << "This is the biggest number of the array: " << *ptr << std::endl;
    std::cout << "This is the memory address of the biggest number in the array: " << ptr << std::endl;

}