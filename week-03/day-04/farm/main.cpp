#include <iostream>
#include "animal.h"
#include "farm.h"


int main()
{
    Animal dog;
    Animal cat;
    Animal bird;
    Animal pig;
    Animal horse;
    Animal parrot;

    Farm farm(10);
    farm.add(&dog);
    farm.add(&cat);
    farm.add(&bird);
    farm.add(&pig);
    farm.add(&horse);
    farm.add(&parrot);

    farm.breed();
    farm.breed();
    farm.breed();
    farm.breed();
    farm.breed();
    farm.infoOfMyAnimals();

    dog.eat();
    dog.eat();
    dog.eat();
    cat.eat();
    farm.slaughter();
    farm.infoOfMyAnimals();
    farm.slaughter();
    farm.infoOfMyAnimals();
    farm.breed();
    farm.breed();
    farm.infoOfMyAnimals();

    return 0;
}