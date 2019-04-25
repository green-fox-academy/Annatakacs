//
// Created by Takacs Anna on 2019-04-25.
//

#ifndef ANAGRAM_ANAGRAM_H
#define ANAGRAM_ANAGRAM_H

#include <iostream>
#include <string>
#include <algorithm>


class Anagram {
public:
    std::string word1;
    std::string word2;

    bool checkIfAnagram(std::string word1, std::string word2);
};


#endif //ANAGRAM_ANAGRAM_H
