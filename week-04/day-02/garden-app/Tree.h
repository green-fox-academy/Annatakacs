//
// Created by Takacs Anna on 2019-04-23.
//

#ifndef GARDEN_APP_TREE_H
#define GARDEN_APP_TREE_H


class Tree {
public:
    Tree(std::string color, float waterAmount);

    Tree();

    int getwaterAmount();

    void setwaterAmount(float waterAmount);

    float getabsorbance();

private:
    std::string _color;
    float _waterAmount;
    float _absorbance;
};


#endif //GARDEN_APP_TREE_H
