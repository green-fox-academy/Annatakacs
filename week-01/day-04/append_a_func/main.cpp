#include <iostream>
#include <string>

std::string appendAFunction(std::string typo);

int main(int argc, char* args[]) {

    // - Create a string variable named `typo` and assign the value `Chinchill` to it
    // - Write a function called `appendAFunc` that gets a string as an input,
    //   appends an 'a' character to its end and returns with a string
    //
    // - Print the result of `appendAFunc(typo)`

    std::string typo = "Chinchill";
    std::string result = appendAFunction(typo);
    std::cout << result << std::endl;
    return 0;
}
std::string appendAFunction(std::string typo) {
    return (typo+"a");
}
