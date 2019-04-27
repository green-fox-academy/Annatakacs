//
// Created by Takacs Anna on 2019-04-23.
//

#ifndef GARDEN_APP_TREE_H
#define GARDEN_APP_TREE_H

#include "Plant.h"

class Tree : public Plant{
public:
    Tree(float waterAmount, std::string color);

    Tree();

    void getInfo();

    bool getNeedsWater() override;

    void getsWatered(int getsWater) override;
};


#endif //GARDEN_APP_TREE_H
