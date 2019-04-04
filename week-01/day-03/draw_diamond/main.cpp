
#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that reads a number from the standard input, then draws a
    // diamond like this:
    //
    //
    //    *
    //   ***
    //  *****
    // *******
    //  *****
    //   ***
    //    *
    //
    // The diamond should have as many lines as the number was

    int rows = 7;

    //std::cout << "Please give me a number" << std::endl;
   // std::cin >> rows;

    for (int i = 1; i <= rows; i++) {
        for (int spaces = i; spaces < rows; spaces++) {
            std::cout << " ";
        } for (int j = 1; j < (2 * (i - 1)); j++) {
            std::cout << "*";
        } std::cout << "" << std::endl;
    }

    /*for (int k = (rows / 2); k >= 0; k--) {
        for (int spaces2 = 1; spaces2 < (rows/2); spaces2--) {
            std::cout << " ";
        } for (int l = (rows / 2); l >= 0; l--) {
            std::cout << "*";
        } std::cout << "" << std::endl;
    } */
    return 0;
}