#include <iostream>

#include <iostream>

int main(int argc, char *args[]) {

    // Write a program that reads a number from the standard input, then draws a
    // square like this:
    //
    //
    // %%%%%%
    // %    %
    // %    %
    // %    %
    // %    %
    // %%%%%%
    //
    // The square should have as many lines as the number was

    int rows;

    std::cout << "Please give me a number" << std::endl;
    std::cin >> rows;

    for (int i = 0; i < rows; i++) {
        if (i == 0 || i == (rows - 1)) {
            for (int j = 0; j < rows; j++) {
                std::cout << "%";
            }
            std::cout << std::endl;
        } else {
            for (int i = 0; i < rows; i++) {
                if (i == 0 || i == (rows -1)) {
                    std::cout << "%";
                } else {
                    std::cout << " ";
                }
            } std::cout << std::endl;
        }
    }

        return 0;
    }
