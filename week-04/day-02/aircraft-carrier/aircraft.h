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

    std::string getType();

    std::stringstream getStatus();

    bool isPriority();

protected:
    int _maxAmmo;
    int _baseDamage;
    int _ammo;
    Type _type;
};


#endif //AIRCRAFT_CARRIER_AIRCRAFT_H
