
#include "Garden.h"
#include "Plant.h"
#include "Flower.h"
#include "Tree.h"

Garden::Garden()
{
    _water = 0;
    _myPlants = {};
}

void Garden::water(int water)
{
    _water = water;
    int counter = 0;
    for (int i = 0; i < _myPlants.size(); ++i) {
        if (_myPlants.at(i)->getNeedsWater()) {
            counter++;
        }
    }
    int getsWater = (_water / counter);
    for (int j = 0; j < _myPlants.size(); ++j) {
        _myPlants.at(j)->getsWatered(getsWater);
    }
}

void Garden::addMyPlants(Plant *plant)
{
    _myPlants.push_back(plant);
}

void Garden::getInfo()
{
    for (int i = 0; i < _myPlants.size(); ++i) {
        _myPlants.at(i)->getInfo();
    }
}