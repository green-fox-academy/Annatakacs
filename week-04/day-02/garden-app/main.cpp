#include <iostream>
#include "Garden.h"
#include "Flower.h"
#include "Tree.h"

int main()
{
    Flower yellow("yellow", 0);
    Flower blue("blue", 6);
    Tree purple("purple", 3);
    Tree orange("orange", 12);

    Garden myGarden(40);

    myGarden.addFlower(yellow);
    myGarden.addFlower(blue);
    myGarden.addTree(purple);
    myGarden.addTree(orange);

    myGarden.info();

    myGarden.watering(40);

    myGarden.info();

    return 0;
}