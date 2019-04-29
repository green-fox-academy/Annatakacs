#include "f35.h"

F35::F35()
{
    _maxAmmo = 12;
    _baseDamage = 50;
}

bool F35::isPriority()
{
    return true;
}

std::string F35::getType()
{
    return "F35";
}