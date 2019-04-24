//
// Created by Takacs Anna on 2019-04-24.
//

#include "stringedInstrument.h"

StringedInstrument::StringedInstrument(int numberOfStrings)
{
    _numberOfStrings = numberOfStrings;
}

StringedInstrument::StringedInstrument()
{
    _numberOfStrings = 0;
}

void StringedInstrument::play()
{
    std::cout << _name << ", a " << _numberOfStrings << "-stringed instrument that goes ";
    sound();
}
