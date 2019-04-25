//
// Created by Takacs Anna on 2019-04-25.
//

#include "anagram.h"

bool Anagram::checkIfAnagram(std::string word1, std::string word2)
{
    std::sort(word1.begin(), word1.end());
    std::sort(word2.begin(), word2.end());
    if (word1.compare(word2) == 0)
        return true;
    else
        return false;
}