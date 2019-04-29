#ifndef AIRCRAFT_CARRIER_AIRCRAFT_H
#define AIRCRAFT_CARRIER_AIRCRAFT_H

#include <iostream>

enum Type {
    f16,
    f35
};

class Aircraft
{
public:
    Aircraft();

    int fight();

    int refill(int refill);

    int refillPriority(int refill);

    virtual std::string getType() = 0;

    std::string getStatus();

    int allDamage();

    virtual bool isPriority() = 0;

    int neededAmmo();

protected:
    int _maxAmmo;
    int _baseDamage;
    int _ammo;
};


#endif //AIRCRAFT_CARRIER_AIRCRAFT_H
