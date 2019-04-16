#include <iostream>
#include <fstream>
#include <string>
#include <exception>

int main () {
    // Write a program that opens a file called "my-file.txt", then prints
    // each line from the file.
    // You will have to create the file, you may use C-programming, although it is not mandatory

    std::ifstream myFile;
    myFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    std::string text;

    try {
        myFile.open("../my-file.txt");
        getline(myFile, text, '.');
        std::cout << text << std::endl;
        myFile.close();

    } catch (std::ifstream::failure& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}