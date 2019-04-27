//
// Created by Takacs Anna on 2019-04-24.
//

#include "Plant.h"

Plant::Plant(float waterAmount, std::string color)
{
    _waterAmount = waterAmount;
    _color = color;
}

Plant::Plant()
{
    _waterAmount = 0;
    _color = "";
    _minWater = 0;
    _absorbance = 0;
    _needsWater = true;
}