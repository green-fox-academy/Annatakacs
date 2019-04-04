#include <iostream>
#include <string>

void doubling(int[], int);

int main(int argc, char* args[]) {

    // - Create an array variable named `numList`
    //   with the following content: `[3, 4, 5, 6, 7]`
    // - Double all the values in the array

    int numList[] = {3, 4, 5, 6, 7};

    int size = sizeof(numList) / sizeof(numList[0]);

    doubling(numList, size);

    return 0;
}
void doubling(int x[], int y) {
    for (int i = 0; i < y; i++) {
        x[i] *= 2;
    }
    for (int j = 0; j < y; j++) {
        std::cout << x[j] << std::endl;
    }
}