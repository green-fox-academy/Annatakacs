//
// Created by Takacs Anna on 2019-04-17.
//

#include "Counter.h"

Counter::Counter(int origin)
{
    _origin = origin;
    _reset = origin;
}

void Counter::setorigin(int origin)
{
    Counter::_origin = origin;
}

void Counter::add(int number)
{
    int add = get();
    setorigin(add + number);
}

void Counter::add()
{
    int add = get();
    setorigin(add + 1);
}

int Counter::get()
{
    return _origin;
}

void Counter::reset()
{
    setorigin(_reset);
}