//
// Created by Takacs Anna on 2019-04-24.
//

#ifndef ZOO_BIRDS_H
#define ZOO_BIRDS_H
#include "egglayers.h"

class Birds : public Egglayers{
public:
    Birds(std::string name);

    std::string getName() override;

};


#endif //ZOO_BIRDS_H
