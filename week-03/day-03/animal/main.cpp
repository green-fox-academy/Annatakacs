#include <iostream>
#include "Animal.h"

int main()
{
    Animal dog;
    dog.play();
    std::cout << dog.gethunger() << ' ' << dog.getthirst() << std::endl;

    Animal cat;
    cat.eat();
    std::cout << cat.gethunger() << ' ' << cat.getthirst() << std::endl;

    Animal parrot;
    parrot.drink();
    std::cout << parrot.gethunger() << ' ' << parrot.getthirst() << std::endl;

    return 0;
}