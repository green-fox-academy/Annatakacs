//
// Created by Takacs Anna on 2019-04-18.
//

#ifndef PETROL_STATION_STATION_H
#define PETROL_STATION_STATION_H

#include "Car.h"

class Station {
public:
    Station(int gasAmount = 500);

    void setgasAmount(int gasAmount);

    int getgasAmount();

    int fill(Car& carobj);

private:
    int _gasAmount;
};


#endif //PETROL_STATION_STATION_H
