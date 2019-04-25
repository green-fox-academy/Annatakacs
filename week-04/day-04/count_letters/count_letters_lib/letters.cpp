//
// Created by Takacs Anna on 2019-04-25.
//

#include "letters.h"

std::map<std::string, int> Letters::makingDictionay(std::string word)
{
    std::map<std::string, int> myMap;
    //std::map<std::string, int>::iterator it;
    std::string x;
    for (unsigned int i = 0; i < word.size(); ++i) {
        x = word.substr(i, 1);
        myMap.insert(std::make_pair(x, i+1));
    }
    return myMap;
}
