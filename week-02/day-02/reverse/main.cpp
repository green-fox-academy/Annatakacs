#include <iostream>
#include <string>

/*
 * Create a method that can reverse an std:string, which is passed as the parameter
 * Use it on this reversed string to check it!
 * Try to solve this using .at() first, and optionally anything else after.
 * Hint: You might use a temporary variable to swap 2 characters or you can use std::swap function.
 */

std::string reverseString(const std::string &text, std::string::iterator x)
{
    std::string forward = "";
    for (; x != (text.begin()-1); x--) {
        forward += *x;
    }
    return forward;
}

int main(int argc, char *args[])
{
    std::string reversed = ".eslaf eb t'ndluow ecnetnes siht ,dehctiws erew eslaf dna eurt fo sgninaem eht fI";

    std::string::iterator reversedIt = (reversed.end()-1);

    std::cout << reverseString(reversed, reversedIt) << std::endl;

    return 0;
}