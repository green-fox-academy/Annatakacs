#include <iostream>

//Given a string, compute recursively a new string where all the 'x' chars have been removed.

std::string cutx(std::string text, char x, char y);

int main() {

    std::string text = "xAxnxnxa";

    char x = 'x';
    char y = 'y';

    std::cout << "The new string is: " << cutx(text, x, y) << std::endl;

    return 0;
}

std::string cutx(std::string text, char x, char y) {
    std::string newtext;
    if (text.size() == 0) {
        return newtext;
    } else if (text.at(0) == x) {
        newtext = "";
        return newtext + cutx(text.substr(1, text.size()), x, y);
    } else {
        newtext = text.at(0);
        return newtext + cutx(text.substr(1, text.size()), x, y);
    }
}