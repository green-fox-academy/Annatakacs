//
// Created by Takacs Anna on 2019-04-24.
//

#ifndef ZOO_REPTILES_H
#define ZOO_REPTILES_H

#include "egglayers.h"

class Reptiles : public Egglayers {
public:
    Reptiles(std::string name);

    std::string getName() override;

};

#endif //ZOO_REPTILES_H
