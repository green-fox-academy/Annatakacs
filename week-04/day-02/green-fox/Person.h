//
// Created by Takacs Anna on 2019-04-23.
//

#ifndef GREEN_FOX_PERSON_H
#define GREEN_FOX_PERSON_H

#include <iostream>

enum Gender {
    MALE,
    FEMALE,
    OTHER
};

class Person {
public:
    Person();

    Person(std::string name, int age, Gender gender);

    std::string getname();

    int getage();

    std::string getgenderAsString();

    virtual void introduce();

    virtual void getGoal();

private:
    std::string _name;
    int _age;
    Gender _gender;

};


#endif //GREEN_FOX_PERSON_H
