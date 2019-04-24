//
// Created by Takacs Anna on 2019-04-24.
//

#include "copier.h"

Copier::Copier(int sizeX, int sizeY, int speed) : Printer2d(sizeX, sizeY), Scanner(speed)
{
    _sizeX = sizeX;
    _sizeY = sizeY;
    _speed = speed;
}

void Copier::copy()
{
    print();
    std::cout << " and " << std::endl;
    scan();
}