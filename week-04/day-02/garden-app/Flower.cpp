//
// Created by Takacs Anna on 2019-04-23.
//

#include "Flower.h"

Flower::Flower(float waterAmount, std::string color)
        : Plant(waterAmount, color)
{
    _minWater = 5.0;
    _absorbance = 0.75;
    _needsWater = true;
}

Flower::Flower()
{
    _minWater = 5.0;
    _absorbance = 0.75;
}

void Flower::getInfo()
{
    if (_waterAmount < _minWater) {
        std::cout << "The " << _color << " Flower needs water" << std::endl;
        _needsWater = true;
    } else {
        std::cout << "The " << _color << " Flower doesn't need water" << std::endl;
        _needsWater = false;
    }
}

bool Flower::getNeedsWater()
{
    return _needsWater;
}

void Flower::getsWatered(int getsWater)
{
    _waterAmount += (_absorbance * getsWater);
}