#ifndef AIRCRAFT_CARRIER_F35_H
#define AIRCRAFT_CARRIER_F35_H

#include "aircraft.h"

class F35 : public Aircraft
{
public:
    F35();

    bool isPriority() override;

    std::string getType();
};


#endif //AIRCRAFT_CARRIER_F35_H
