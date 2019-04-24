//
// Created by Takacs Anna on 2019-04-24.
//

#ifndef FLYABLE_HELICOPTER_H
#define FLYABLE_HELICOPTER_H

#include "vehicle.h"
#include "flyable.h"

class Helicopter : public Vehicle, Flyable {
public:

    void land() override;

    void fly() override;

    void takeOff() override;

};


#endif //FLYABLE_HELICOPTER_H
