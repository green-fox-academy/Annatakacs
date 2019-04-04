#include <iostream>
#include <string>

std::string appendAFunction(std::string, char);

int main(int argc, char* args[]) {

    // - Create a string variable named `typo` and assign the value `Chinchill` to it
    // - Write a function called `appendAFunc` that gets a string as an input,
    //   appends an 'a' character to its end and returns with a string
    //
    // - Print the result of `appendAFunc(typo)`

    std::string typo = "Chinchill";

    char a = 'a';
    std::cout << appendAFunction(typo, a) << std::endl;
    return 0;
}
std::string appendAFunction(std::string x, char y) {
    return (x + y);
}
