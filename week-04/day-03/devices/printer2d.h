//
// Created by Takacs Anna on 2019-04-24.
//

#ifndef DEVICES_PRINTER2D_H
#define DEVICES_PRINTER2D_H

#include "printer.h"

class Printer2d : public Printer{
public:
    Printer2d(int sizeX, int sizeY);

    std::string getSize() override;

protected:
    int _sizeX;
    int _sizeY;

};


#endif //DEVICES_PRINTER2D_H
