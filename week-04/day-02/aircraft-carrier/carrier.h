#ifndef AIRCRAFT_CARRIER_CARRIER_H
#define AIRCRAFT_CARRIER_CARRIER_H

#include "aircraft.h"
#include <vector>

class Carrier
{
public:
    Carrier(int initalAmmo, int healthPoints, int storeOfAmmo);

    void add(Aircraft *aircraft);

    void fill();

    void fight(Carrier *carrier);

    std::string getStatus();

protected:
    std::vector<Aircraft *> _aircrafts;
    int _storeOfAmmo;
    int _healthPoints;
    int _initialAmmo;
};


#endif //AIRCRAFT_CARRIER_CARRIER_H
