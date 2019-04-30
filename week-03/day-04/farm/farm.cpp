
#include "farm.h"

Farm::Farm(int slots)
{
    _slots = slots;
}

void Farm::breed()
{
    if (_slots > 0) {
        Animal animal;
        _animals.push_back(&animal);
        _slots--;
    } else {
        std::cout << "There are not enough barns for a new animal." << std::endl;
    }
}

void Farm::slaughter()
{
    int minHunger = 50;
    int numberInRow = 0;
    for (int i = 0; i < _animals.size(); ++i) {
        if (_animals.at(i)->gethunger() < minHunger) {
            minHunger = _animals.at(i)->gethunger();
            numberInRow = i;
        }
    }
    _animals.erase(_animals.begin() + numberInRow);
    _slots++;
}

void Farm::add(Animal *animal)
{
    if (_slots > 0) {
        _animals.push_back(animal);
        _slots--;
    } else {
        std::cout << "There are not enough barns for a new animal." << std::endl;
    }
}

void Farm::infoOfMyAnimals()
{
    std::cout << "Animals in barn: " << _animals.size() << std::endl;
}