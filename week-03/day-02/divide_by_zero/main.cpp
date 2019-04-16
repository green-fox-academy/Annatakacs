#include <iostream>
#include <fstream>

void dividingTen(float x, int y);

int main() {
    // Create a function that takes a number
    // divides ten with it,
    // and prints the result.
    // It should print "fail" if the parameter is 0

    int ten = 10;
    std::cout << "Please give me a number." << std::endl;
    float number;
    std::cin >> number;

    dividingTen(number, ten);

    return 0;
}
void dividingTen(float x, int y)
{
    try {
        if (x == 0) {
            throw 0;
        } else {
            std::cout << "The solution is: " << (y/x);
        }
    } catch (int& e) {
        std::cerr << "fail" << std::endl;
    }

}