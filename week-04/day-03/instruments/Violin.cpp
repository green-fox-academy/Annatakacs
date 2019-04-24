//
// Created by Takacs Anna on 2019-04-24.
//

#include "Violin.h"

Violin::Violin(int numberOfStrings) : StringedInstrument (numberOfStrings)
{
    _numberOfStrings = numberOfStrings;
    _name = "Violin";
}

Violin::Violin()
{
    _name = "Violin";
    _numberOfStrings = 4;
}
void Violin::sound()
{
    std::cout << "Duum-duum-duum" << std::endl;
}