//
// Created by Takacs Anna on 2019-04-18.
//
#include <iostream>
#include "Station.h"
#include "Car.h"

Station::Station(int gasAmount)
{
    setgasAmount(gasAmount);
}

void Station::setgasAmount(int gasAmount)
{
    Station::_gasAmount = gasAmount;
}

int Station::getgasAmount()
{
    return _gasAmount;
}

int Station::fill(Car &carobj)
{
    while (!carobj.isFull()) {
        carobj.fill();
        Station::_gasAmount--;
        std::cout << "Filling car!" << std::endl;
    }
    std::cout << "The station's gas amount is: " << Station::_gasAmount << std::endl;
}