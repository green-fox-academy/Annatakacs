//
// Created by Takacs Anna on 2019-04-23.
//
#include <iostream>
#include <vector>
#include "Garden.h"

Garden::Garden(int wateringAmount)
{
    _wateringAmount = wateringAmount;
}

Garden::Garden()
{
    _wateringAmount = 0;
    std::cout << "Watering with " << _wateringAmount << std::endl;
}

void Garden::addFlower(Flower flower)
{
    _flowers.push_back(flower);
}

void Garden::addTree(Tree tree)
{
    _trees.push_back(tree);
}

int Garden::countWateringFlowers()
{
    int counter = 0;
    for (unsigned int i = 0; i < _flowers.size(); i++) {
        if (_flowers.at(i).getwaterAmount() < 5) {
            counter++;
        }
    }
}

int Garden::countWateringTrees()
{
    int counter = 0;
    for (unsigned int i = 0; i < _trees.size(); i++) {
        if (_trees.at(i).getwaterAmount() < 10) {
            counter++;
        }
    }
}

void Garden::watering(int wateringAmount)
{
    float amount = wateringAmount / (countWateringFlowers() + countWateringTrees());
    std::cout << amount << std::endl;
    float flowerWaterAmount = Flower::getwaterAmount();
    float flowerAbsorbance = Flower::getabsorbance();
    Flower::setwaterAmount(flowerWaterAmount + (amount * flowerAbsorbance));
    std::cout << Flower::getwaterAmount() << std::endl;

    float treeWaterAmount = Tree::getwaterAmount();
    float treeAbsorbance = Tree::getabsorbance();
    Tree::setwaterAmount(treeWaterAmount + (amount * treeAbsorbance));
    std::cout << Tree::getwaterAmount() << std::endl;
}

void Garden::info()
{
    for (unsigned int i = 0; i < _flowers.size(); i++) {
        if (_flowers.at(i).getwaterAmount() < 5) {
            std::cout << "The plant needs watering" << std::endl;
        } else
            std::cout << "The flower doesn't need watering" << std::endl;
    }
    for (unsigned int i = 0; i < _trees.size(); i++) {
        if (_trees.at(i).getwaterAmount() < 10) {
            std::cout << "The tree needs watering" << std::endl;
        } else {
            std::cout << "The flower doesn't need watering" << std::endl;
        }
    }
}