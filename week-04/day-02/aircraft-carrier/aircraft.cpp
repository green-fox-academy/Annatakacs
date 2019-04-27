#include "aircraft.h"
#include <sstream>

Aircraft::Aircraft()
{
    _ammo = 0;
}

int Aircraft::fight()
{
    int damage = (_baseDamage * _ammo);
    _ammo = 0;
    return  damage;
}

int Aircraft::refill(int refill)
{
    int possible = (_maxAmmo - _ammo);
    return (refill - possible);
}

std::string Aircraft::getType()
{
    if (_type == f16) {
        return "F16";
    } else {
        return "F35";
    }
}

std::stringstream Aircraft::getStatus()
{
    std::stringstream stream;
    stream << "Type " << _type << ", Ammo: " << _ammo << ", Base Damage: " << _baseDamage << ", All Damage: " << (_ammo * _baseDamage);
    return stream;
}

bool Aircraft::isPriority()
{
    if(_type == f35)
        return true;
    else
        return false;

}