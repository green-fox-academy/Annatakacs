//
// Created by Takacs Anna on 2019-04-24.
//

#include "reptiles.h"

Reptiles::Reptiles(std::string name) : Egglayers(name)
{
    _name = name;
}

std::string Reptiles::getName()
{
    return _name;
}