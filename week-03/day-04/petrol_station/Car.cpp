//
// Created by Takacs Anna on 2019-04-18.
//

#include "Car.h"

Car::Car(int capacity, int gasAmount)
{
    _capacity = capacity;
    _gasAmount = gasAmount;
}

void Car::setgasAmount(int gasAmount)
{
    Car::_gasAmount = gasAmount;
}

void Car::setcapacity(int capacity)
{
    Car::_capacity = capacity;
}

int Car::getgasAmount()
{
    return _gasAmount;
}

int Car::getcapacity()
{
    return _capacity;
}

bool Car::isFull()
{
    if(_capacity == _gasAmount)
        return true;
     else
        return false;
}

void Car::fill()
{
    if (_capacity != _gasAmount)
        Car::_gasAmount++;
}