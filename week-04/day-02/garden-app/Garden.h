//
// Created by Takacs Anna on 2019-04-23.
//

#ifndef GARDEN_APP_GARDEN_H
#define GARDEN_APP_GARDEN_H

#include <vector>
#include "Flower.h"
#include "Tree.h"


class Garden : public Flower, public Tree{
public:
    Garden(int wateringAmount);

    Garden();

    void addFlower(Flower flower);

    void addTree(Tree tree);

    int countWateringFlowers();

    int countWateringTrees();

    void watering(int wateringAmount);

    void info();

private:
    int _wateringAmount;
    std::vector<Flower> _flowers;
    std::vector<Tree> _trees;

};


#endif //GARDEN_APP_GARDEN_H
