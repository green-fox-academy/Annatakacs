//
// Created by Takacs Anna on 2019-04-24.
//

#ifndef INSTRUMENTS_ELECTRICGUITAR_H
#define INSTRUMENTS_ELECTRICGUITAR_H

#include "stringedInstrument.h"

class ElectricGuitar : public StringedInstrument {
public:
    ElectricGuitar(int numberOfStrings);

    ElectricGuitar();

    void sound() override;
};


#endif //INSTRUMENTS_ELECTRICGUITAR_H
