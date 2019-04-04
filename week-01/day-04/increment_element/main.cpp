
#include <iostream>
#include <string>

void increment(int[], int);

int main(int argc, char* args[]) {

    // - Create an array variable named `t`
    //    with the following content: `[1, 2, 3, 4, 5]`
    // - Increment the third element
    // - Print the third element

    int t[] = {1, 2, 3, 4, 5};

    int size = sizeof(t) / sizeof(t[0]);

    increment(t, size);

    return 0;
}
void increment(int x[], int y) {
    for (int i = 0; i < y; i++) {
        if (i == 2) {
            x[i] = x[i] + 1;
        }
    }
    std::cout << x[2] << std::endl;
}