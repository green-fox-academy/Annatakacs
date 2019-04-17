//
// Created by Takacs Anna on 2019-04-17.
//

#ifndef COUNTER_COUNTER_H
#define COUNTER_COUNTER_H

#include <iostream>


class Counter {
public:
    Counter(int origin);

    void setorigin(int origin);

    void add(int number);

    void add();

    int get();

    void reset();

private:
    int _origin = 0;
    int _reset = 0;

};


#endif //COUNTER_COUNTER_H
