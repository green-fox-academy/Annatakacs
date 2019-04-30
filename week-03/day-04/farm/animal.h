//
// Created by Takacs Anna on 2019-04-30.
//

#ifndef FARM_ANIMAL_H
#define FARM_ANIMAL_H

#include <iostream>

class Animal
{
public:

    Animal();

    void sethunger(int hunger);

    void setthirst(int thirst);

    int gethunger();

    int getthirst();

    std::string getName();

    void eat();

    void drink();

    void play();

private:
    int _hunger;
    int _thirst;
    std::string _name;

};


#endif //FARM_ANIMAL_H
