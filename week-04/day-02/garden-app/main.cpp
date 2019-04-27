#include <iostream>
#include "Garden.h"
#include "Flower.h"
#include "Tree.h"

int main()
{
    Flower flower1(3, "yellow");
    Flower flower2(3, "blue");
    Tree tree1(5, "purple");
    Tree tree2(5, "orange");

    Garden garden;
    garden.addMyPlants(&flower1);
    garden.addMyPlants(&flower2);
    garden.addMyPlants(&tree1);
    garden.addMyPlants(&tree2);

    garden.getInfo();
    std::cout << std::endl;

    garden.water(40);
    garden.getInfo();
    std::cout << std::endl;

    garden.water(70);
    garden.getInfo();
    std::cout << std::endl;


    return 0;
}