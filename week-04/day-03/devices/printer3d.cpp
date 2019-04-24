//
// Created by Takacs Anna on 2019-04-24.
//

#include "printer3d.h"

Printer3d::Printer3d(int sizeX, int sizeY, int sizeZ)
{
    _sizeX = sizeX;
    _sizeY = sizeY;
    _sizeZ = sizeZ;
}

std::string Printer3d::getSize()
{
    return std::to_string(_sizeX) + " X " + std::to_string(_sizeY) + " X " + std::to_string(_sizeZ);
}