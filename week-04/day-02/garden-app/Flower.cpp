//
// Created by Takacs Anna on 2019-04-23.
//

#include "Flower.h"

Flower::Flower(std::string color, float waterAmount)
{
    _waterAmount = waterAmount;
}

Flower::Flower()
{
    _absorbance = 0.75;
}

int Flower::getwaterAmount()
{
    return _waterAmount;
}

float Flower::getabsorbance()
{
    return _absorbance;
}

void Flower::setwaterAmount(float waterAmount)
{
    _waterAmount = waterAmount;
}