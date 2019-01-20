#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that asks for two numbers and prints the bigger one

    int number1, number2;
    std::cout << "Please give me a number and fun things will happen..." << std::endl;
    std::cin >> number1;
    std::cout << "Please give me a second number and fun things will happen..." << std::endl;
    std::cin >> number2;

    if (number1 > number2) {
        std::cout << number1 << " is bigger" << std::endl;
    } else {
        std::cout << number2 << " is bigger" << std::endl;
    }

    return 0;
}