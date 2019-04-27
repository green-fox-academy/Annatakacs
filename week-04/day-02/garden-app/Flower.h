//
// Created by Takacs Anna on 2019-04-23.
//

#ifndef GARDEN_APP_FLOWER_H
#define GARDEN_APP_FLOWER_H

#include <iostream>
#include "Plant.h"

class Flower : public Plant {
public:
    Flower(float waterAmount, std::string color);

    Flower();

    void getInfo();

    bool getNeedsWater() override;

    void getsWatered(int getsWater) override;

};


#endif //GARDEN_APP_FLOWER_H
