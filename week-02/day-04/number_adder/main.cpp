#include <iostream>

void numberAdder(int n);

int main() {
    int n ;

    std::cout << "Please give me a number!" << std::endl;
    std::cin >> n;

    numberAdder(n);

    return 0;
}

void numberAdder(int n) {
    if (n < 1)
        return;
    numberAdder(n - 1);
    std::cout << n << std::endl;
}