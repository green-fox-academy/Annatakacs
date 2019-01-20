#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that asks for two integers
    // The first represents the number of chickens the farmer has
    // The second represents the number of pigs owned by the farmer
    // It should print how many legs all the animals have

    int chickens;
    int pigs;

    std::cout << "How many chickens does the farmer have?" << std::endl;
    std::cin >> chickens;

    std::cout << "How many pigs does the farmer have?" << std::endl;
    std::cin >> pigs;

    int chicken_legs = chickens * 2;
    int pig_legs = pigs * 4;

    std::cout << "All animals have " << chicken_legs +  pig_legs << " legs" << std::endl;

    return 0;
}