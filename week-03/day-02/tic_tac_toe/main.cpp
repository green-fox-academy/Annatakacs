#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Write a function that takes a filename as string,
    // open and read it. The file data represents a tic-tac-toe
    // game result. Return 'X'/'O'/'draw' based on which player
    // has winning situation.

    cout << ticTacResult("win-o.txt");
    // should print O

    cout << ticTacResult("win-x.txt");
    // should print X

    cout << ticTacResult("draw.txt");
    // should print draw

    return 0;
}
