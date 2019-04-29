#include "f16.h"

F16::F16()
{
    _maxAmmo = 8;
    _baseDamage = 30;
}

bool F16::isPriority()
{
    return false;
}

std::string F16::getType()
{
    return "F16";
}