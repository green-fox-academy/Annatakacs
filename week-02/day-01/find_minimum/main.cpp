#include <iostream>

int *findMinimum(int x[], int y);

int main()
{
    // Create a function which takes an array (and its length) as a parameter
    // and returns a pointer to its minimum value

    int numbers[] = {12, 4, 66, 101, 87, 3, 15};
    int size = (sizeof(numbers)/sizeof(numbers[0]));


    int *result = findMinimum(numbers, size);

    std::cout << "The minimum value's address is: " << result << std::endl;
    std::cout << "The minimum value's address is: " << &numbers[5] << std::endl;


    return 0;
}
int *findMinimum(int x[], int y) {
    int *z = x;
    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < y; ++j) {
           if (x[j] < x[j+1]) {
               z = &x[j];
           }
        }
    }
    return z;
}