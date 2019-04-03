#include <iostream>

int main(int argc, char *args[]) {

    // Write a program that reads a number from the standard input, then draws a
    // pyramid like this:
    //
    //
    //    *
    //   ***
    //  *****
    // *******
    //
    // The pyramid should have as many lines as the number was

    int rows = 5;
    int space;

    //std::cout << "Please give me a number" << std::endl;
    //std::cin >> rows;

    for (int i = 1; i <= rows; i++) {
        for (int space = i; space < rows; space++) {
            std::cout << " ";
        } for (int j = 0; j < (2 * i -1); j++) {
            std::cout << "*";
        } std::cout << "" << std:: endl;
    }


        return 0;
    }
