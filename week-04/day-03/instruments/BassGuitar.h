//
// Created by Takacs Anna on 2019-04-24.
//

#ifndef INSTRUMENTS_BASSGUITAR_H
#define INSTRUMENTS_BASSGUITAR_H

#include "stringedInstrument.h"

class BassGuitar : public StringedInstrument {
public:
        BassGuitar(int numberOfStrings);

        BassGuitar();

        void sound() override;
};


#endif //INSTRUMENTS_BASSGUITAR_H
