//
// Created by Takacs Anna on 2019-04-17.
//

#ifndef ANIMAL_ANIMAL_H
#define ANIMAL_ANIMAL_H

#include <iostream>


class Animal {
public:


    void sethunger(int hunger);

    void setthirst(int thirst);

    int gethunger();

    int getthirst();

    void eat();

    void drink();

    void play();

private:
    int _hunger = 50;
    int _thirst = 50;

};


#endif //ANIMAL_ANIMAL_H
