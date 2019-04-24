//
// Created by Takacs Anna on 2019-04-24.
//

#ifndef DEVICES_PRINTER3D_H
#define DEVICES_PRINTER3D_H

#include "printer.h"

class Printer3d : public Printer {
public:
    Printer3d(int sizeX, int sizeY, int sizeZ);

    std::string getSize() override;

protected:
    int _sizeX;
    int _sizeY;
    int _sizeZ;

};


#endif //DEVICES_PRINTER3D_H
