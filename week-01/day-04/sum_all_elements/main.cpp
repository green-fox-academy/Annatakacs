#include <iostream>
#include <string>


int main(int argc, char* args[]) {

    // - Create an array variable named `ai`
    //   with the following content: `[3, 4, 5, 6, 7]`
    // - Print the sum of the elements in `ai`

    int ai[] = {3, 4, 5, 6, 7};
    int size = sizeof(ai) / sizeof(ai[0]);

    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += ai[i];
    }

    std::cout << sum << std::endl;


    return 0;
}

