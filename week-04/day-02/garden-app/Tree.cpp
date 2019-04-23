//
// Created by Takacs Anna on 2019-04-23.
//
#include <iostream>
#include "Tree.h"

Tree::Tree(std::string color, float waterAmount)
{
    _waterAmount = waterAmount;
};

Tree::Tree()
{
    _absorbance = 0.4;
}

int Tree::getwaterAmount()
{
    return _waterAmount;
}

void Tree::setwaterAmount(float waterAmount)
{
    _waterAmount = waterAmount;
}

float Tree::getabsorbance()
{
    return _absorbance;
}
