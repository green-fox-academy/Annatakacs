#include <iostream>
#include <string>

int sum(int);

int main(int argc, char* args[]) {

    // Write a function called `sum` that returns the sum of numbers from zero to the given parameter

    std::cout << "Please give me a number" << std::endl;
    int parameter;

    std::cin >> parameter;

    std::cout << sum(parameter) << std::endl;

    return 0;
}
int sum(int x) {
    int result = 0;
    for (int i = 0; i <= x; i++) {
         result += i;
    }
    return result;
}