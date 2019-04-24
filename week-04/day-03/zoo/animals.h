//
// Created by Takacs Anna on 2019-04-24.
//

#ifndef ZOO_ANIMALS_H
#define ZOO_ANIMALS_H

#include <iostream>

enum Gender {
    FEMALE,
    MALE
};

class Animals {
public:
    Animals(std::string name);

    std::string genderToString();

    virtual std::string getName() = 0;

    virtual std::string breed() = 0;

    void feed();

    void drink();

protected:
    std::string _name;
    int _age;
    Gender _gender;

};


#endif //ZOO_ANIMALS_H
