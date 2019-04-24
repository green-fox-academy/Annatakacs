//
// Created by Takacs Anna on 2019-04-24.
//

#include "BassGuitar.h"

BassGuitar::BassGuitar(int numberOfStrings) : StringedInstrument (numberOfStrings)
{
    _numberOfStrings = numberOfStrings;
    _name = "Bass Guitar";
}

BassGuitar::BassGuitar()
{
    _name = "Bass Guitar";
    _numberOfStrings = 4;
}

void BassGuitar::sound()
{
    std::cout << "Duum-duum-duum" << std::endl;
}