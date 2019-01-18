#include <iostream>
#include <string>


int main() {

    // - Create an array variable named `numList`
    //   with the following content: `[3, 4, 5, 6, 7]`
    // - Double all the values in the array

    int numList[] = {3, 4, 5, 6, 7};
    int size = ((sizeof(numList)) / (sizeof(numList[0])));
    for (int i = 0; i < size; i++){
        numList[i] *= 2;
    }
    for (int i = 0; i < size; i++) {
        std::cout << numList[i] << std::endl;
    }
    return 0;
}
