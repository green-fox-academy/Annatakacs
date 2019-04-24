//
// Created by Takacs Anna on 2019-04-24.
//

#include "animals.h"

Animals::Animals(std::string name)
{
    _name = name;
}

std::string Animals::genderToString()
{
    switch  (_gender) {
        case FEMALE:
            return "female";
        case MALE:
            return "male";
    }
}
