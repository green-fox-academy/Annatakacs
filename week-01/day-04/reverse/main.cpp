#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    // - Create an array variable named `aj`
    //   with the following content: `[3, 4, 5, 6, 7]`
    // - Reverse the order of the elements in `aj`
    // - Print the elements of the reversed `aj`

    int aj[] = {3, 4, 5, 6, 7};
    int array[5];

    int size = sizeof(aj) / sizeof(aj[0]);

    for (int i = 0; i <= size; i++) {
        array[size-i] = aj[i];
    }

    for (int j = 0; j <= size; j++) {
        aj[j] = array[j];
        std::cout << aj[j] << std::endl;
    }

    return 0;
}