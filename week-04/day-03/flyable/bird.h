//
// Created by Takacs Anna on 2019-04-24.
//

#ifndef FLYABLE_BIRD_H
#define FLYABLE_BIRD_H

#include "animal.h"
#include "flyable.h"

class Bird : public Animal, Flyable {
public:
    void land() override;

    void fly() override;

    void takeOff() override;

};


#endif //FLYABLE_BIRD_H
