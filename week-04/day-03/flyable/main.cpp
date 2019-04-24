#include <iostream>
#include "bird.h"
#include "helicopter.h"

int main()
{
    Helicopter helicopter;
    helicopter.land();
    helicopter.fly();
    helicopter.takeOff();

    Bird bird;
    bird.land();
    bird.takeOff();
    bird.fly();

    return 0;
}