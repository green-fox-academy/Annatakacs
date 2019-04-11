#include <iostream>

//Given a string, compute recursively (no loops) a new string where all the lowercase 'x' chars have been changed to 'y' chars.

std::string xchange(std::string text, char x, char y);

int main() {

    std::string text = "Alexa";

    //std::string::iterator it = text.begin();

    char x = 'x';
    char y = 'y';

    std::cout << "The new string is: " << xchange(text, x, y) << std::endl;

    return 0;
}

std::string xchange(std::string text, char x, char y) {
    std::string newtext;
    if (text.size() == 0) {
        return newtext;
    } else if (text.at(0) == x) {
        newtext = y;
        return newtext + xchange(text.substr(1, 1), x, y);
    } else {
        newtext = text.at(0);
        return newtext + xchange(text.substr(1, text.size()), x, y);
    }
}