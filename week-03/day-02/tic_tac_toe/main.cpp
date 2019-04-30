#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

std::vector<std::vector<char>> fileToVector(std::string filename);

std::string ticTacResult(std::vector<std::vector<char>> xoVector);

int main()
{
    // Write a function that takes a filename as string,
    // open and read it. The file data represents a tic-tac-toe
    // game result. Return 'X'/'O'/'draw' based on which player
    // has winning situation.

    //cout << ticTacResult("win-o.txt");
    // should print O

    //cout << ticTacResult("win-x.txt");
    // should print X

    //cout << ticTacResult("draw.txt");
    // should print draw

    std::vector<std::vector<char>> xoVector1 = fileToVector("../win-o.txt");
    std::vector<std::vector<char>> xoVector2 = fileToVector("../win-x.txt");
    std::vector<std::vector<char>> xoVector3 = fileToVector("../draw.txt");
    /*
    for (int i = 0; i < xoVector.size(); ++i) {
        for (int j = 0; j < xoVector.at(i).size(); ++j) {
            std::cout << xoVector[i][j];
        }
        std::cout << std::endl;
    }*/

    std::cout << ticTacResult(xoVector1) << std::endl;
    std::cout << ticTacResult(xoVector2) << std::endl;
    std::cout << ticTacResult(xoVector3) << std::endl;

    return 0;
}

std::vector<std::vector<char>> fileToVector(std::string filename)
{
    std::ifstream myFile(filename);
    myFile.exceptions(std::ifstream::badbit | std::ifstream::failbit);
    std::vector<std::vector<char>> xoVector;

    try {
        std::string line;
        for (int i = 0; getline(myFile, line); ++i) {
            std::vector<char> temp;
            for (int j = 0; j < 3; ++j) {
                char y = line.at(j);
                temp.push_back(y);
            }
            xoVector.push_back(temp);
        }

    } catch (std::ifstream::failure &e) {
        std::cerr << e.what() << std::endl;
    }
    return xoVector;
}

std::string ticTacResult(std::vector<std::vector<char>> xoVector)
{
    int row = 3;
    for (int i = 0; i < row; ++i) {
        if (xoVector[i][0] == 'X' && xoVector[i][1] == 'X' && xoVector[i][2] == 'X') {
            return "X";
        } else if (xoVector[i][0] == 'O' && xoVector[i][1] == 'O' && xoVector[i][2] == 'O') {
            return "0";
        }
    }
    for (int j = 0; j < row; ++j) {
        for (int i = 0; i < row; ++i) {
            if (xoVector[0][i] == 'X' && xoVector[1][i] == 'X' && xoVector[2][i] == 'X') {
                return "X";
            } else if (xoVector[0][i] == 'O' && xoVector[1][i] == 'O' && xoVector[2][i] == 'O') {
                return "0";
            }
        }
    }
    int j = 0;
    if (xoVector[j][j] == 'X' && xoVector[j + 1][j + 1] == 'X' && xoVector[j + 2][j + 2] == 'X') {
        return "X";
    } else if (xoVector[j][j] == 'O' && xoVector[j + 1][j + 1] == 'O' && xoVector[j + 2][j + 2] == 'O') {
        return "0";
    }

    if (xoVector[j][j + 2] == 'X' && xoVector[j + 1][j + 1] == 'X' && xoVector[j + 2][j] == 'X') {
        return "X";
    } else if (xoVector[j][j + 2] == 'O' && xoVector[j + 1][j + 1] == 'O' && xoVector[j][j + 2] == 'O') {
        return "0";
    }

    return "draw";
}
