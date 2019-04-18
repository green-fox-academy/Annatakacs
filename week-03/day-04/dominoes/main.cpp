#include <iostream>
#include <vector>

#include "domino.h"

std::vector<Domino> initializeDominoes()
{
    std::vector<Domino> dominoes;
    dominoes.push_back(Domino(5, 2));
    dominoes.push_back(Domino(4, 6));
    dominoes.push_back(Domino(1, 5));
    dominoes.push_back(Domino(6, 7));
    dominoes.push_back(Domino(2, 4));
    dominoes.push_back(Domino(7, 1));
    return dominoes;
}

void swapDominoes(Domino &x, Domino &y);

int main(int argc, char* args[])
{
    std::vector<Domino> dominoes = initializeDominoes();
    // You have the list of Dominoes
    // Order them into one snake where the adjacent dominoes have the same numbers on their adjacent sides
    // eg: [2, 4], [4, 3], [3, 5] ...

    for (unsigned int i = 0; i < (dominoes.size() - 1); i++) {
        for (unsigned int j = 1; j < (dominoes.size() - i); j++) {
            if (dominoes.at(i).getValues().second == dominoes.at(i + j).getValues().first) {
                swapDominoes(dominoes[i+1], dominoes[i+j]);
            }
        }
    }

    for (unsigned int i = 0; i < dominoes.size(); i++) {
        std::cout << dominoes.at(i).toString() << " ";
    }

    return 0;
}

void swapDominoes(Domino &x, Domino &y)
{
    Domino temp = x;
    x = y;
    y = temp;
}
