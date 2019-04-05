#include <iostream>
#include <string>

void unique(int[], int, int[]);

int main(int argc, char *args[]) {

    //  Create a function that takes a list of numbers as a parameter
    //  Don't forget you have pass the size of the list as a parameter as well
    //  Returns a list of numbers where every number in the list occurs only once

    //  Example
    //int numbers[] = {1, 11, 34, 11, 52, 61, 1, 34};
    //std::cout << (unique(numbers)) << std::endl;
    //  should print: `[1, 11, 34, 52, 61]`

    std::cout << "Please give me a number" << std::endl;
    int size;
    std::cin >> size;

    std::cout << "Please give me " << size << " numbers" << std::endl;
    int array[size];
    int number;
    for (int i = 0; i < size; i++) {
        std::cin >> number;
        array[i] = number;

    }

    //for (int j = 0; j < size; j++) {
        //std::cout << array[j] << " ";
    //}

    for (int k = 0; k < size; k++) {
        for (int l = 0; l < size - 1; l++) {
            if (array[l] > array[l + 1]) {
                int temp = array[l + 1];
                array[l + 1] = array[l];
                array[l] = temp;
            }
        }
    }

    std::cout << "Bubble sort: " << std::endl;
    for (int j = 0; j < size; j++) {
        std::cout << array[j] << std::endl;
    }

    int temp_arr[size];

    unique(array, size, temp_arr);

    return 0;
}
void unique(int x[], int y, int temp_arr[]) {

    for (int i = 0; i < y; i++) {
        if (x[i] != x[i+1]) {
            temp_arr[i] = x[i];
        }
    }
    for (int j = 0; j < y; j++) {
        std::cout << temp_arr[j] << " ";
    }
}