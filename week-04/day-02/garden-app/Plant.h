//
// Created by Takacs Anna on 2019-04-24.
//

#ifndef GARDEN_APP_PLANT_H
#define GARDEN_APP_PLANT_H

#include <iostream>

class Plant {

public:
    Plant(float waterAmount, std::string color);

    Plant();

    virtual bool getNeedsWater() = 0;

    virtual void getsWatered(int getsWater) = 0;

    virtual void getInfo() = 0;

protected:
    float _waterAmount;
    std::string _color;
    float _minWater;
    float _absorbance;
    bool _needsWater;
};


#endif //GARDEN_APP_PLANT_H
