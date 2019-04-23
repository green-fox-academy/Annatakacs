//
// Created by Takacs Anna on 2019-04-23.
//
#include <iostream>
#include "Mentor.h"

Mentor::Mentor(std::string name, int age, Gender gender, Level level = INTERMEDIATE) : Person(name, age, gender)
{
    _level = level;
}

Mentor::Mentor()
{
    _level = INTERMEDIATE;
}

std::string Mentor::getLevelAsString()
{
    switch (_level) {
        case JUNIOR:
            return "junior";
        case INTERMEDIATE:
            return "intermediate";
        case SENIOR:
            return "senior";
    }
}

void Mentor::getGoal()
{
    std::cout << "My goal is: Educate brilliant junior software developers." << std::endl;
}

void Mentor::introduce()
{
    std::cout << "Hi, I'm " << getname() << " , a " << getage() << " year old " << getgenderAsString() << _level << " mentor." << std::endl;
}
