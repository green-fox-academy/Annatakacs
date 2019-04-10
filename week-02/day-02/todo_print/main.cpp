#include <iostream>
#include <string>


int main(int argc, char* args[])
{
    std::string todoText = " - Buy milk\n";
    // Add "My todo:" to the beginning of the todoText
    // Add " - Download games" to the end of the todoText
    // Add " - Diablo" to the end of the todoText but with indentation

    // Expected outpt:

    // My todo:
    //  - Buy milk
    //  - Download games
    //      - Diablo

    std::string text1 = "My todo:\n";
    std::string text2 = " - Download games\n";
    std::string text3 = "\t - Diablo";


    todoText.insert(0, "My todo:\n", text1.size());

    todoText.insert(todoText.size(), " - Download games\n", text2.size());

    todoText.insert(todoText.size(), "\t - Diablo", text3.size());

    std::cout << todoText << std::endl;

    return 0;
}