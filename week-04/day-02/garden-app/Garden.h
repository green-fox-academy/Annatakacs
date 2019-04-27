//
// Created by Takacs Anna on 2019-04-23.
//

#ifndef GARDEN_APP_GARDEN_H
#define GARDEN_APP_GARDEN_H

#include <vector>
#include "Flower.h"
#include "Tree.h"


class Garden : public Flower, public Tree {
public:
    Garden();

    void water(int getsWater);

    void addMyPlants(Plant *plant);

    void getInfo();

private:
    std::vector<Plant *> _myPlants;
    int _water;
};


#endif //GARDEN_APP_GARDEN_H
