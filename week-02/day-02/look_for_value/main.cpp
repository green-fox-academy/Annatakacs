#include <iostream>
#include <vector>

int FindNumber(int *array, int size, int number);

int main()
{
    // Create a function which takes an array (and it's length) and a number as a parameter
    // the function should return index where it found the given value
    // if it can't find the number return 0

    int array[] = {5, 10, 15, 20, 25};
    int size = (sizeof(array)/sizeof(array[0]));
    int number;



    std::cout << "Which number should I find?" << std::endl;
    std::cin >> number;

    std::cout << FindNumber(array, size, number);

    return 0;
}
int FindNumber(int *array, int size, int number) {
    for (int i = 0; i < size; i++) {
        if (array[i] == number) {
            return i;
        }
    }
    return 0;
}