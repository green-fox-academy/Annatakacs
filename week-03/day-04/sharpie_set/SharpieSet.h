//
// Created by Takacs Anna on 2019-04-21.
//

#ifndef SHARPIE_SET_SHARPIESET_H
#define SHARPIE_SET_SHARPIESET_H

#include "Sharpie.h"

class SharpieSet {
public:

    SharpieSet(std::vector<Sharpie> sharpies);

    int CountUsable();

    void removeTrash();

    void printUsable();

private:
    std::vector<Sharpie> _sharpies;
};


#endif //SHARPIE_SET_SHARPIESET_H
