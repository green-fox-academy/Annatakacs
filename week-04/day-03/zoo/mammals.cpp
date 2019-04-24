//
// Created by Takacs Anna on 2019-04-24.
//

#include "mammals.h"

Mammals::Mammals(std::string name) : Animals(name)
{
    _name = name;
};

std::string Mammals::getName()
{
    return _name;
}

std::string Mammals::breed()
{
    return " pushing miniature versions out.";
}