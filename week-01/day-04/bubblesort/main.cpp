#include <iostream>
#include <string>

//  Create a function that takes a list of numbers as parameter
//  Don't forget you have to pass the size of the list as a parameter as well
//  Returns a list where the elements are sorted in ascending numerical order by using bubble sort
//  Make a second boolean parameter, if it's `true` sort that list descending

int main(int argc, char *args[]) {

    std::cout << "How big should your array be?" << std::endl;
    int size;
    std::cin >> size;

    int array[size];
    std::cout << "Please tell me " << size << " numbers: " << std::endl;
    int number;
    for (int i = 0; i < size; i++) {
        std::cin >> number;
        array[i] = number;
    }


    std::cout << "Array before sorting: " << std::endl;
    for (int j = 0; j < size; j++) {
        std::cout << array[j] << " ";
    }

    std::cout << std::endl;
    std::cout << "It should be sorted in ascending order. (True = 1 or false = 0) " << std::endl;
    bool sort;
    std::cin >> sort;

    if (sort == true) {
        for (int k = 0; k < size; k++) {
            for (int l = 0; l < (size - 1); l++) {
                if (array[l] > array[l + 1]) {
                    int temp = array[l + 1];
                    array[l + 1] = array[l];
                    array[l] = temp;
                }
            }
        }

        std::cout << std::endl;
        std::cout << "Array after sorting: " << std::endl;
        for (int m = 0; m < size; m++) {
            std::cout << array[m] << " ";

        }
    } else {
        for (int k = 0; k < size; k++) {
            for (int l = 0; l < (size - 1); l++) {
                if (array[l] < array[l + 1]) {
                    int temp = array[l + 1];
                    array[l + 1] = array[l];
                    array[l] = temp;
                }
            }
        }

        std::cout << std::endl;
        std::cout << "Array after sorting: " << std::endl;
        for (int m = 0; m < size; m++) {
            std::cout << array[m] << " ";
        }
    }


    return 0;
}
