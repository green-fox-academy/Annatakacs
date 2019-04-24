//
// Created by Takacs Anna on 2019-04-24.
//

#ifndef FLYABLE_ANIMAL_H
#define FLYABLE_ANIMAL_H

#include <iostream>

enum Gender {
    FEMALE,
    MALE
};

class Animal {
public:
    std::string genderToString();

    std::string getName();

    std::string breed();

    void feed();

    void drink();

protected:
    std::string _name;
    int _age;
    Gender _gender;

};


#endif //FLYABLE_ANIMAL_H
