//
// Created by Takacs Anna on 2019-04-24.
//

#include "birds.h"

Birds::Birds(std::string name) : Egglayers(name)
{
    _name = name;
}

std::string Birds::getName()
{
    return _name;
}