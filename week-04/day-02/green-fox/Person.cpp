//
// Created by Takacs Anna on 2019-04-23.
//

#include "Person.h"

Person::Person(std::string name, int age, Gender gender)
{
    _name = name;
    _age = age;
    _gender = gender;

}

Person::Person()
{
    _name = "Jane Doe";
    _age = 30;
    _gender = FEMALE;
}

std::string Person::getname()
{
    return _name;
}

int Person::getage()
{
    return _age;
}

std::string Person::getgenderAsString()
{
    switch (_gender) {
        case MALE:
            return "male";
        case FEMALE:
            return "female";
        case OTHER:
            return "other";
    }
}

void Person::introduce()
{
    std::cout << "Hi, I'm " << _name << " a " << _age << " year old " << getgenderAsString() << " ." << std::endl;
}

void Person::getGoal()
{
    std::cout << "My goal is: Live for the moment!" << std::endl;
}

