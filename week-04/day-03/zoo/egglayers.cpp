//
// Created by Takacs Anna on 2019-04-24.
//

#include "egglayers.h"

Egglayers::Egglayers(std::string name) : Animals(name)
{
    _name = name;
}

std::string Egglayers::breed()
{
    return " by laying eggs.";
}