#include <iostream>
#include <string>

void print(int[], int);

int main(int argc, char* args[]) {

    // - Create an array variable named `numbers`
    //   with the following content: `[4, 5, 6, 7]`
    // - Print all the elements of `numbers`

    int numbers[] = {4, 5, 6, 7};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    print(numbers, size);

    return 0;
}
void print(int x[], int y) {
    for (int i = 0; i < y; i++) {
        std::cout << x[i] << std::endl;
        x[i]++;
    }
}