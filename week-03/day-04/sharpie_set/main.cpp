#include <iostream>
#include <vector>
#include "SharpieSet.h"
#include "Sharpie.h"

std::vector<Sharpie> initializeSharpieSet()
{
    std::vector<Sharpie> sharpies;

    sharpies.push_back(Sharpie ("blue", 1, 100));
    sharpies.push_back(Sharpie ("purple", 1, 75));
    sharpies.push_back(Sharpie ("green", 1, 50));
    sharpies.push_back(Sharpie ("black", 1, 25));
    sharpies.push_back(Sharpie ("brown", 1, 0));
    sharpies.push_back(Sharpie ("yellow", 1, 0));
    sharpies.push_back(Sharpie ("orange", 1, 12));
    sharpies.push_back(Sharpie ("red", 1, 0));
    sharpies.push_back(Sharpie ("pink", 1, 0));

    return sharpies;
}

int main()
{
    SharpieSet mySharpies(initializeSharpieSet());

    std::cout << "You have " << mySharpies.CountUsable() << " Sharpies left." << std::endl;

    mySharpies.removeTrash();

    std::cout << "You have the following Sharpies left after removing the trash." << std::endl;

    mySharpies.printUsable();

    return 0;
}