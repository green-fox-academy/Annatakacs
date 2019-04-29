#ifndef AIRCRAFT_CARRIER_F16_H
#define AIRCRAFT_CARRIER_F16_H

#include "aircraft.h"

class F16 : public Aircraft
{
public:
    F16();

    bool isPriority() override;

    std::string getType();
};


#endif //AIRCRAFT_CARRIER_F16_H
