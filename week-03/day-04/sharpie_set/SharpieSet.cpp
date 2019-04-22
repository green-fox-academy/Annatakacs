//
// Created by Takacs Anna on 2019-04-21.
//
#include <vector>
#include "SharpieSet.h"
#include "Sharpie.h"

SharpieSet::SharpieSet(std::vector <Sharpie> sharpies)
{
    _sharpies = sharpies;
}

int SharpieSet::CountUsable()
{
    int counter = 0;
    for (int i = 0; i < SharpieSet::_sharpies.size(); i++) {
        if (SharpieSet::_sharpies.at(i).getinkAmount() > 0) {
            counter++;
        }
    }
    return counter;
}

void SharpieSet::removeTrash()
{
    for (int i = 0; i < SharpieSet::_sharpies.size(); i++) {
        if (SharpieSet::_sharpies.at(i).getinkAmount() == 0) {
            SharpieSet::_sharpies.erase(SharpieSet::_sharpies.begin() + i);
            i--;
        }
    }
}

void SharpieSet::printUsable()
{
    for (int i = 0; i < SharpieSet::_sharpies.size(); i++) {
        std::cout << SharpieSet::_sharpies.at(i).getcolor() << std::endl;
    }
}