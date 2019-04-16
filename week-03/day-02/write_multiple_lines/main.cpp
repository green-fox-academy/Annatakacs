#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <exception>

void writeIntoFile(std::string path, std::string word, int number);

  // Create a function that takes 3 parameters: a path, a word and a number
  // and is able to write into a file.
  // The path parameter should be a string that describes the location of the file you wish to modify
  // The word parameter should also be a string that will be written to the file as individual lines
  // The number parameter should describe how many lines the file should have.
  // If the word is "apple" and the number is 5, it should write 5 lines
  // into the file and each line should read "apple"


int main() {

    std::string path = "../text.txt";
    std::string word;
    int number;

    std::cout << "What word should be written into the file? " << std::endl;
    std::cin >> word;

    std::cout << "How many times?" << std::endl;
    std::cin >> number;

    writeIntoFile(path, word, number);

    return 0;
}

void writeIntoFile(std::string path, std::string word, int number) {
    std::ofstream myFile;
    myFile.exceptions(std::ofstream::failbit | std::ofstream::badbit);

    try {
        myFile.open(path);
        for (int i = 0; i < number; i++) {
            myFile << word << std::endl;
        }
        myFile.close();
    } catch (std::ofstream::failure &e) {
        std::cout << e.what() << std::endl;
    }
}
