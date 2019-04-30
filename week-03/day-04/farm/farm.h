//
// Created by Takacs Anna on 2019-04-30.
//

#ifndef FARM_FARM_H
#define FARM_FARM_H

#include <vector>
#include "Animal.h"

class Farm
{
public:
    Farm(int slots);

    void breed();

    void slaughter();

    void add(Animal *animal);

    void infoOfMyAnimals();

private:
    std::vector<Animal *> _animals;
    int _slots;
};


#endif //FARM_FARM_H
