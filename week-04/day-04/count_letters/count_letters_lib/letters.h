//
// Created by Takacs Anna on 2019-04-25.
//

#ifndef COUNT_LETTERS_LETTERS_H
#define COUNT_LETTERS_LETTERS_H

#include <iostream>
#include <map>
#include <string>

class Letters {
public:
    std::string word;

    std::map<std::string, int> makingDictionay(std::string word);
};


#endif //COUNT_LETTERS_LETTERS_H
