#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void doubleToSingle();

int main()
{
    // Create a program that decrypts the file called "duplicated-chars.txt",
    // and pritns the decrypred text to the terminal window.

    doubleToSingle();

    return 0;
}

void doubleToSingle()
{
    std::fstream myFile("../duplicated-chars.txt");
    myFile.exceptions(std::ifstream::badbit | std::ifstream::failbit);
    std::string text;

    try {
        std::string line;
        while (getline(myFile, line)) {
            text += line;
        }
        myFile.close();
    } catch (std::ifstream::failure &e) {
        std::cout << e.what() << std::endl;
    }
    int counter = 0;
    std::string single;
    std::string::iterator it =  text.begin();
    for (; it != text.end(); ++it) {
        counter++;
        if(counter % 2 == 0) {
            single += *it;
        }
    }
    std::cout << single << std::endl;
}