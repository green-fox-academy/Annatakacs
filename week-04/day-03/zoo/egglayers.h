//
// Created by Takacs Anna on 2019-04-24.
//

#ifndef ZOO_EGGLAYERS_H
#define ZOO_EGGLAYERS_H

#include "animals.h"

class Egglayers : public Animals {
public:

    Egglayers(std::string name);

    //virtual std::string getName() = 0;

    std::string breed() override;

};


#endif //ZOO_EGGLAYERS_H
