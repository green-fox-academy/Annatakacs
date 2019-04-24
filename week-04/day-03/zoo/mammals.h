//
// Created by Takacs Anna on 2019-04-24.
//

#ifndef ZOO_MAMMALS_H
#define ZOO_MAMMALS_H

#include "animals.h"

class Mammals : public Animals {
public:
    Mammals(std::string name);

    std::string getName() override;

    std::string breed() override;

};


#endif //ZOO_MAMMALS_H
