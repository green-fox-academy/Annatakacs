#include <iostream>
#include <fstream>
#include <string>
#include <exception>

int countLines();

int main () {
    // Write a function that takes a filename as string,
    // then returns the number of lines the file contains.
    // It should return zero if it can't open the file

    countLines();

    return 0;
}
int countLines()
{
    try {
        std::ifstream myFile("text.txt");
        std::string text;
        getline(myFile, text, '&');
    }

}