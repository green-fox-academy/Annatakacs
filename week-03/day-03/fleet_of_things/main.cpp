#include <iostream>

#include "fleet.h"

int main(int argc, char* args[])
{
    Fleet fleet;
    // Create a fleet of things to have this output:
    // 1. [ ] Get milk
    // 2. [ ] Remove the obstacles
    // 3. [x] Stand up
    // 4. [x] Eat lunch

    Thing todo1("Get Milk");
    Thing todo2("Remove the obstacles");
    Thing todo3("Stand up");
    Thing todo4("Eat lunch");

    todo3.complete();
    todo4.complete();

    fleet.add(todo1);
    fleet.add(todo2);
    fleet.add(todo3);
    fleet.add(todo4);

    std::cout << fleet.toString() << std::endl;
    return 0;

}