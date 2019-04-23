//
// Created by Takacs Anna on 2019-04-23.
//

#ifndef GARDEN_APP_FLOWER_H
#define GARDEN_APP_FLOWER_H

#include <iostream>

class Flower {
public:
    Flower(std::string color, float waterAmount);

    Flower();

    int getwaterAmount();

    float getabsorbance();

    void setwaterAmount(float waterAmount);

private:
    std::string _color;
    float _waterAmount;
    float _absorbance;

};


#endif //GARDEN_APP_FLOWER_H
