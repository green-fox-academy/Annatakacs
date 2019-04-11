#include <iostream>

//Given a non-negative int n, return the sum of its digits recursively (no loops).
// Note that mod (%) by 10 yields the rightmost digit (126 % 10 is 6),
// while divide (/) by 10 removes the rightmost digit (126 / 10 is 12).

int sum(int n);

int main() {

    int n;
    std::cout << "Please enter your number: " << std::endl;
    std::cin >> n;

    std::cout << "The sum is: " << sum(n);

    return 0;
}

int sum(int n) {
    if (n < 0) {
        return 0;
    }
    else {
        return n + sum(n - 1);
    }
}