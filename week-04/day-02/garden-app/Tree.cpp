//
// Created by Takacs Anna on 2019-04-23.
//
#include <iostream>
#include "Tree.h"

Tree::Tree(float waterAmount, std::string color) : Plant(
        waterAmount, color)
{
    _minWater = 10.0;
    _absorbance = 0.4;
    _needsWater = true;
}

Tree::Tree()
{
    _minWater = 10.0;
    _absorbance = 0.4;
}

void Tree::getInfo()
{
    if (_waterAmount < _minWater) {
        std::cout << "The " << _color << " Tree needs water" << std::endl;
        _needsWater = true;
    } else {
        std::cout << "The " << _color << " Tree doesn't need water" << std::endl;
        _needsWater = false;
    }
}

bool Tree::getNeedsWater()
{
    return _needsWater;
}

void Tree::getsWatered(int getsWater)
{
    _waterAmount += (_absorbance * getsWater);
}