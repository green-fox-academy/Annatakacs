#include <iostream>
#include <fstream>
#include <string>
#include <exception>

int numberOfLines(std::string);

int main()
{
    // Write a function that takes a filename as string,
    // then returns the number of lines the file contains.
    // It should return zero if it can't open the file

    std::cout << "The number of lines: " << numberOfLines("../text.txt");

    return 0;
}

int numberOfLines(std::string filename)
{
    std::ifstream myFile;
    int numberOfLines = 0;
    myFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try {
        myFile.open(filename);
        std::string text;
        while (getline(myFile, text)) {
            numberOfLines++;
        }
    } catch (std::ifstream::failure& e) {
        std::cout << e.what() << std::endl;
    }
    return numberOfLines;
}