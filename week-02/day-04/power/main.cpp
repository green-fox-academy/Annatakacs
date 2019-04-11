#include <iostream>

//Given base and n that are both 1 or more, compute recursively (no loops) the value of base to the n power,
// so powerN(3, 2) is 9 (3 squared).

int tothepower(int base, int power);

int main() {

    std::cout << "Please give me a base." << std::endl;
    int base;
    std::cin >> base;

    std::cout << "Please give me the power of the base." << std::endl;
    int power;
    std::cin >> power;

    std::cout << "The solution is: " << tothepower(base, power);

    return 0;
}

int tothepower(int base, int power) {
    if (power < 1) {
        return 1;
    } else {
        power = power - 1;
        return (base * tothepower(base, power));

    }
}