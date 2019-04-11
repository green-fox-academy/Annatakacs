#include <iostream>

//Find the greatest common divisor of two numbers using recursion.

int commondiv(int number1, int number2);

int commondiv2(int number1, int number2);

int main() {

    int number1 = 54;
    int number2 = 45;

    if (number1 > number2) {
        std::cout << "The greatest common divisor of these numbers is: " << commondiv(number1, number2) << std::endl;
    } else {
        std::cout << "The greatest common divisor of these numbers is: " << commondiv2(number1, number2) << std::endl;

    }

    return 0;
}

int commondiv(int number1, int number2) {
    int constnum1 = number1;
    if (number1 % number2 == 0) {
        return number2;
    } else {
        (number1)
    }

}