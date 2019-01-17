#include <iostream>
#include <string>

int sum (int numbers[], int size);

int main(int argc, char* args[]) {

    // - Write a function called `sum` that sum all the numbers
    //   until the given parameter and returns with an integer

    int numbers[] = {2,4,6,8,10,12};
    std::cout << sum(numbers,6) << std::endl;
    return 0;
}
int sum (int numbers[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += numbers[i];
    }
    return sum;
}