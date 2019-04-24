//
// Created by Takacs Anna on 2019-04-24.
//

#include "animal.h"

std::string Animal::genderToString()
{
    switch (_gender) {
        case FEMALE:
            return "female";
        case MALE:
            return "male";
    }
}