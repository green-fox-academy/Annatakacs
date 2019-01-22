#include <iostream>

int main()
{
    // Create a program which first asks for a number
    // this number indicates how many integers we want to store in an array
    // and than asks for numbers till the user fills the array
    // It should print out the biggest number in the given array and the memory address of it

    int number;

    std::cout << "Please give me a number!" << std::endl;
    std::cin >> number;

    int array[number];

    std::cout << "Please provide me " << number << " numbers 1-by-1" << std::endl;
    for (int i = 0; i < number; i++) {
        std::cout << "New number: " << std::endl;
        std::cin >> array[i];
    }


    int temp = -999;
    for (int i = 0; i < number; i++) {
        if (array[i] > temp) {
            temp = array[i];
        }
    }
    std::cout << "The biggest number is: " << temp << std::endl;

    return 0;
}
