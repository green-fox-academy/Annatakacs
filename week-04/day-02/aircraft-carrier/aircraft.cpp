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
    if (possible > refill) {
        _ammo += possible;
    }
    return (refill - possible);
}

int Aircraft::refillIfNotEnough(int refill)
{
    _ammo += refill;
    return 0;
}

std::string Aircraft::getType()
{
    if (_type == f16) {
        return "F16";
    } else {
        return "F35";
    }
}

std::string Aircraft::getStatus()
{
    std::string stream;
    stream = "Type " + getType() + ", Ammo: " + std::to_string(_ammo) + ", Base Damage: " + std::to_string(_baseDamage) + ", All Damage: " + std::to_string(_ammo * _baseDamage);
    return stream;
}

int Aircraft::allDamage()
{
    return (_ammo * _baseDamage);
}

bool Aircraft::isPriority()
{
    if(_type == f35)
        return true;
    else
        return false;

}

int Aircraft::neededAmmo()
{
    return (_maxAmmo - _ammo);
}