#include <iostream>
#include <fstream>
#include <string>

void copyFiles(std::string, std::string);

// Write a function that reads all lines of a file and writes the read lines to an other file (a.k.a copies the file)
// It should take the filenames as parameters
// It should return a boolean that shows if the copy was successful

int main() {

    copyFiles("../input.txt", "../copy.txt");

    return 0;
}

void copyFiles(std::string input, std::string copy) {
    std::ifstream iFile;
    std::ofstream cFile;
    iFile.exceptions(std::ofstream::failbit | std::ofstream::badbit);
    cFile.exceptions(std::ofstream::failbit | std::ofstream::badbit);
    try {
        iFile.open(input);
        cFile.open(copy);
        std::string text;
        while (getline(iFile, text)) {
            cFile << text;
        }
        iFile.close();
        cFile.close();
    } catch (std::ofstream::failure &e) {
        std::cout << e.what() << std::endl;
    }
}
