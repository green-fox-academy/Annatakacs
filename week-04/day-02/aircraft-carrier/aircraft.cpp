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
    return damage;
}

int Aircraft::refill(int refill)
{
    int possible = (_maxAmmo - _ammo);
    _ammo += possible;
    int output = refill - possible;
    return output;
}

int Aircraft::refillPriority(int refill)
{
    if (isPriority()) {
        int possible = (_maxAmmo - _ammo);
        if (possible < refill) {
            _ammo += possible;
            int output = refill - possible;
            return output;
        } else {
            _ammo += refill;
            return 0;
        }
    } else {
        return refill;
    }
}

std::string Aircraft::getStatus()
{
    std::string stream;
    stream =
            "Type " + getType() + ", Ammo: " + std::to_string(_ammo) + ", Base Damage: " + std::to_string(_baseDamage) +
            ", All Damage: " + std::to_string(_ammo * _baseDamage);
    return stream;
}

int Aircraft::allDamage()
{
    return (_ammo * _baseDamage);
}

int Aircraft::neededAmmo()
{
    return (_maxAmmo - _ammo);
}