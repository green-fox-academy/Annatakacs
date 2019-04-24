//
// Created by Takacs Anna on 2019-04-24.
//

#ifndef INSTRUMENTS_STRINGEDINSTRUMENT_H
#define INSTRUMENTS_STRINGEDINSTRUMENT_H

#include "instrument.h"

class StringedInstrument : public  Instrument{
public:
    StringedInstrument(int numberOfStrings);

    StringedInstrument();

    virtual void sound() = 0;

    void play() override;

protected:
    int _numberOfStrings;
};


#endif //INSTRUMENTS_STRINGEDINSTRUMENT_H
